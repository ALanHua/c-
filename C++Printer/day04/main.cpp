//
//  main.cpp
//  day04
//
//  Created by yhp on 2018/10/25.
//  Copyright © 2018 none. All rights reserved.
//

#include <iostream>
#include <string>
#include <cstring>

using namespace std;

class NA {
private:
    int     n_;
    double  d_;
public:
    NA(){
    }
//    重载了取地址运算符
    NA* operator &(){
        return NULL;
    }
};

class R {
public:
    /**
     友元声明,向这个函数授权允许访问本类成员
     */
    friend ostream& operator <<(ostream& o,const R& x);
    friend istream& operator >>(istream& i,R& x);
    friend R operator+(const R& lh,const R& rh);
    
    explicit R(int n,int d=1):n_(n),d_(d){
        if (d < 0) {
            n_ = -n;
            d_ = -d;
        }
        for (int i = d_; i>1; i--) {
            if ((d_ % i == 0) && (n_ % i == 0)) {
                d_ /= i;
                n_ /= i;
                break;
            }
        }
    }
    
private:
    int n_;
    int d_;
};

ostream& operator <<(ostream& o,const R& x){
    o << x.n_ << '/' << x.d_;
    return o;
}

istream& operator >>(istream& i,R& x)
{
    char c;
    int n,d;
    i >> n >> c >> d;
    x = R(n,d);// 匿名对象
    return i;
}

R operator+(const R& lh,const R& rh)
{
    int n = lh.n_ * rh.d_ + lh.d_ * rh.n_;
    double d = rh.d_ * lh.d_;
    return R(n,d);
}

class S{
public:
    friend ostream& operator <<(ostream& o,const S& x){
        return o << x.p_; // 等价 return o
    }
    
    S(const char* str = ""){
        len_= static_cast<int> (strlen(str));
        p_ = new char[len_ + 1];
        strcpy(p_, str);
    }
    ~S(){
        if (p_) {
            delete [] p_;
            p_ = NULL;
        }
    }
    
    // 赋值运算符
    S& operator=(const S& x){
        if (&x == this) {
            return *this;
        }
        len_ = x.len_;
        delete [] p_;
        p_ = new char[len_ + 1];
        strcpy(p_, x.p_);
        return *this; // 当前对象
    }
    
    char& operator[](int idx){
        if (idx > len_ || idx < 0) {
            return p_[0];
        }
        return p_[idx];
    }
    
private:
    char* p_;
    int  len_;
    S(const S& x);// 私有的copy构造，禁止copy
};

class P {
public:
    P(const char* n,int a,float s)
    :name_(n),age_(a),salary_(s){
        
    }
    operator double(){ // 不写返回类型
        return salary_;
    }
    operator int(){ // 不写返回类型
        return age_;
    }
    operator string(){ // 不写返回类型
        return name_;
    }
    
private:
    string name_;
    int    age_;
    float  salary_;
};

class A {
public:
    A(int n,int v = 0):p_(new int[n]),len_(n){
        for (int i = 0; i<n; i++) {
            p_[i] = v;
        }
    }
    
    ~A(){
        if(p_){
            delete [] p_;
            p_ = NULL;
        }
    }
    
    void operator ()(int start,int step){
        for (int i = 0; i < len_; i++) {
            p_[i] = start + i * step;
        }
    }
    
    int operator()(){
        int sum = 0;
        for (int i = 0; i < len_; i++) {
            sum += p_[i];
        }
        return sum;
    }
    
private:
    int* p_;
    int  len_;
};

/**
 c++中,运算符被被当成函数，允许程序员自己规定运算符如何工作
 方法就是自己定义响应的运算符函数
 运算符函数的形参和返回z类型尽量用引用，尽量加const
 格式:
 返回类型 operator 运算符(参数表)
 
 2，在全局函数中如果需要访问对象的非公开成员，需要在类中
 对这个全局函数进行授权，方法是把这个函数声明成友元
 友元不是成员，一般在类里声明在外面定义，也可以在类里直接定义
 但它依旧是友元，不是成员，如果需要的话，一个类也可以声明为友元
 这等于把宁外一个类的所有的成员函数都声明为这个类的友元了。
 而且友元声明是单向且不传递的
 
 运算符函数的定义格式z二：成员函数
 返回类型 operator运算符(除第一个操作数之外的参数表)
 
 双目运算符：运算结果类型operator运算符(第w二个操作数)
 单目运算符: 运算结果类型operator运算符()
 以成员函数定义时，第一个操作数作为了当前对象，不需要作为实参传递
 只需要传递剩余的操作数就可以了，在运算符函数里可以通过*this访问第一操作数。
 ....
 只能用成员函数的[] ,(), =,->,类型转换
 如果有指针成员指向动态内存，还应该自己写h赋值运算函数来
 实现copy构造函数相似的功能
 ....
 类型转换运算符函数格式
     operator 类型名()
 不写返回值,返回类型跟类型名一致，只能是成员函数
 ....
 圆括号作为运算符时，参数个数不定
 支持圆括号运算符的对象也称为函数对象，因为使用的形式特别像调用函数
 */
int main(int argc, const char * argv[]) {
    
    NA  a,b;
    
    cout << &a << endl;
    cout << &b << endl;
    
    R r1(6,8),r2(8,-12);
    
    cout << r1 << ","<< r2 << endl;
//    cin >> r1 >> r2;
//    cout << r1 << ","<< r2 << endl;
    cout << r1 + r2 << endl;
    S c;
    S d("123");
    c = d;
    cout << c << "," << d << endl;
    
    cout << d[1] << endl;
    
    P A1("Andy",10,8000);
    
    string info = A1;
    double money = A1;
    int age = A1;
    cout << info << "," << money << "," << age << endl;
    
    A t(5);
    t(5,1);
    cout << t() << endl;
    return 0;
}
