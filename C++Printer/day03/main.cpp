//
//  main.cpp
//  day03
//
//  Created by yhp on 2018/10/22.
//  Copyright © 2018 none. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

class CSD1212Stu{
    string name;
    //   静态成员变量，属于这个类的对象公用一份，在类外面初始化时需要加::
    static string teacher;
public:
    CSD1212Stu(const string& n){
        this->name = n;
    }
    void listen(){
        cout << name << "在上课," << teacher << endl;
    }
//    静态成员函数是类对象公共的行为，不一样与对象，yinc函数中不存在this
//    只能访问静态成员，访问非静态成员必须指明对象
    static void changeTeacher(const string &t){
        teacher = t;
    }
};

// 单例模式
/**
 c++ 11之后的static 是线程安全的
 任意两个单例不能相互引用对方的实例
 */
class ChairMan {
private:
    const string name;
//   初始化列表
    ChairMan(string name):name(name){}
//   copy 构造静止
    ChairMan(ChairMan const& ){}
//   禁止=运算
    ChairMan& operator = (ChairMan const&);
//   禁止析构
    ~ChairMan(){}
public:
//   这样有问题
    static ChairMan& getInstance(){
        static ChairMan cm("xi da da");
        return cm;
    }
    void show(){
        cout << "are you ok! i am " << name << endl;
    }
};

class Buffer {
    string name;
public:
    Buffer(const string& filename):name(filename){
        cout << filename << "分配缓冲区"<< endl;
    }
    
    ~Buffer(){
        cout << name << "释放缓冲区"<< endl;
    }
};

/*
 p()表示0初始化
 */
class File {
    string path_;
    Buffer* p;
public:
    File(const string& path = "无名"):path_(path),p(){
        cout << this  <<"创建文件" << path_ << endl;
    }
    ~File(){
        cout << this << path_ << " 释放" << endl;
    }
    
    void open(){
        p = new Buffer(path_);
    }
    void close(){
        delete p;
        p = NULL;
    }
};

string CSD1212Stu::teacher = "andy";

/**
 析构函数：对象释放时会自动调用的函数，函数名为类名，总是无惨
 总是无惨
 默认析构函数:如果一个类没有定义析构函数，编译器会自动产生一个
 什么也不做的析构函数
 */

/**
 匿名对象：直接定义一个对象但不给提供名字，这个对象会在这个x语句之后j
 立即释放，编译器还会最大限度的优化性能，提供一次性匿名对象
------
 类名(参数) ---没有变量名，对象只能当场使用
 只要一个参数时，匿名对象可以看成是类型c转换
 如果要禁止这个特性，可以用explicit修饰
 */
class R{
    int n; // 分子
    int d; // 分母
public:
    /**
     这样匿名对象就不能自动转换了
     */
    explicit R(int n,int d = 1):n(n),d(d){
        cout << "R(" << n << '/' << d << ")" << endl;
    }
    
    R add(const R& r2){
        int nd = d * r2.d;
        int nn = d * r2.n + n * r2.d;
//        R result(nn,nd);
//        return result;
        return R(nn,nd); // 匿名对象
    }
    R mul(const R& r2){
        return R(n*r2.n,d*r2.d);
    }
    void show(){
        cout << n << '/' << d << endl;
    }
    ~R(){
        cout << "~" << n << '/' << d << endl;
    }
};

class A {
typedef int T;
    T*  a_;
    int len_;
public:
    /**
     类型后面跟一个()就是零初始化操作
     */
    A(int n,T init = T()):a_(new T[n]){
        for (int i = 0; i < n; i++) {
            a_[i] = init;
        }
        len_ = n;
        cout << a_ <<"创建数组" << len_ << "个元素" << init << endl;
    }
    /*
     copy 构造函数，一个类如果没有定义copy构造函数，编译器
     会自动生成一个copy构造函数，内容时候逐个负责对应的成员，
     一般能满足，但如果有指针成员指向动态内存的时候就会出问题
     */
    A(const A& r){// 实参是个A类型的就对象
        len_ = r.len_;
        a_ = new T(len_);
        for (int i = 0; i < len_; i++) {
            a_[i] = r.a_[i];
        }
        cout << this << " copy from" << r.a_ << " " << endl;
    }
    
    ~A(){
        cout << "释放了数组" << a_ << endl;
        delete [] a_;
        a_ = NULL;
    }
    T& at(int idx){
        if (idx > len_ || idx < 0) {
            throw idx;
        }
        return a_[idx];
    }
    int size(){
        return len_;
    }
    
    void resize(int newsize,const T& val = T()){
        if (newsize <= len_) {
            len_ = newsize;
        }else{
            T* np = new T[newsize];
            for (int i = 0; i < len_; i++) {
                np[i] = a_[i];
            }
            for (int j = len_; j < newsize; j++) {
                np[j] = val;
            }
            delete[] a_;
            a_ = np;
            len_ = newsize;
        }
    }
    void print() {
        for (int i = 0; i < len_; i++) {
            cout << a_[i] << " ";
        }
        cout << endl;
    }
    void fill(const T& start,const T& step = T()){
        for (int i = 0; i < len_; i++) {
            a_[i] = start + step*i;
        }
    }
};

/**
 过滤数组中的偶数，返回原数组
 fillter(x) 新建对象arr，x初始化，调用copy构造函数A(cosnt A& r)
 参数x
 */
A fillter(A arr){
    for (int i = 0; i < arr.size(); i++) {
        if (!(arr.at(i) & 1)) {
            cout << arr.at(i) << " " ;
        }
    }
    cout << endl;
    return arr;
}

int main(int argc, const char * argv[]) {
    
    CSD1212Stu a("安然");
    CSD1212Stu b("sundy");
    a.listen();
    b.listen();
    CSD1212Stu::changeTeacher("权哥");
    a.listen();
    b.listen();
    
    ChairMan& c1 = ChairMan::getInstance();
    c1.show();
    ChairMan& c2 = ChairMan::getInstance();
    c2.show();
    cout << &c1 << "," << &c2 << endl;
    
    File aFile("a");
    File* p2 = new File("/etc/passwd");
    p2->open();
    p2->close();
    delete p2;p2 = NULL;
    
    R a1(2,5), b1(3,4);
    a1.add(b1).show();
    cout << "-----111--------" << endl;
    a1.add(R(3,8)).show();
    cout << "-----222-------" << endl;
//    a1.add(3).show();// 匿名对象自动类型转换R(3）
//    cout << "-------------" << endl;
    a1.mul(b1).show();
    cout << "-----333-------" << endl;
    
    A x(20);
    x.at(3) = 5;
    x.print();
    A y(10,6);
    y.print();
    y.resize(15,9);
    y.print();
    fillter(y).print();
    return 0;
}
