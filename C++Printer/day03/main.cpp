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
 b任意两个单例不能相互引用对方的实例
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
 */
class R{
    int n; // 分子
    int d; // 分母
public:
    R(int n,int d = 1):n(n),d(d){
        cout << "R(" << n << '/' << d << ")" << endl;
    }
    R add(const R& r2){
        int nd = d * r2.d;
        int nn = d * r2.n + n * r2.d;
//        R result(nn,nd);
//        return result;
        return R(nn,nd); // 匿名对象
    }
    void show(){
        cout << n << '/' << d << endl;
    }
    ~R(){
        cout << "~" << n << '/' << d << endl;
    }
};


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
    cout << "-------------" << endl;
    a1.add(R(3,8)).show();
    cout << "-------------" << endl;
    
    return 0;
}
