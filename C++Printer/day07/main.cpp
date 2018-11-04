//
//  main.cpp
//  day07
//
//  Created by yhp on 2018/11/4.
//  Copyright © 2018 none. All rights reserved.
//

#include <iostream>
#include <string>
#include <exception>
#include <new>
using namespace std;

/**
 如果抛出的异常没有被捕获处理，系统会调用terminate() 函数终止
 程序。set_terminate(func)可以指定在terminate时自动调用那个
 函数。
 异常传递机制:o从throw开始离开正常执行流程，在本函数内找
 有没有包含它的try{}块，如果有依次查找它的catch块直到第一个
 类型匹配的为止进入这个catch快执行处理，之后从最后一个
 catch块之后继续执行，如果没有包含的try块或者没有n类型匹配
 的catch块，异常数据继续传递到上层函数(调用它的那个函数)
 中重复这个过程。如果直到main函数还没处理。系统就调
 terminat()终止程序

 异常声明：一个函数可以声明自己ee可能抛出哪些类型的异常格式为：
 返回类型 函数名（参数列表）throw(异常类型列表）;
 int func(int a[],int idx) throw(double,int,string);
 如果在函数内部抛出了不在列表中的异常，则会引发意外
 可以通过set_unexcepted(func)来设置意外情况是调用func.
 
 标准异常： exceptio类
 定义子类覆盖父类的虚函数时，异常声明的内容不能超出父类中
 这个函数的异常声明内容
 标准库中国b抛出的异常类型都是exception类的子类
 */



void func()
{
    throw 123;
//    throw 4.5;
//    throw "hello";
}
void beforedie(){
    cout << "code is life" << endl;
}

void f1(){
    try {
        cout << "trt catch" << endl;
        int n;
        cin >> n;
        if (n == 1) {
            throw 1;
        }
        if (n == 2) {
            throw 2.2;
        }
        if (n == 0) {
            return;
        }
        
        throw string("error");
    } catch (long e) {
        cout << "long " << e << endl;
    }catch (double e){
        cout << "double " << e << endl;
    }
    
    cout << "---end of f1" << endl;
}

void f2(){
    try {
        f1();
        cout << "----in f2 ---" << endl;
    } catch (int e) {
        cout << "int " << e << endl;
    }
    
    cout << "----end of f2 ---" << endl;
}

void f3(int n) throw(int,double)
{
    if(n == 1) throw 123;
    if(n == 2) throw 4.5;
    throw "out of range";
}

void func3(){
    cout << "异常类型不在列表中" << endl;
}

class A {
public:
    explicit A(int n) throw(){
        p_ = new (nothrow)int[n];
        len_ = n;
    }
    ~A(){
        
    }
    int& operator [] (int index){
        if (index < 0) {
            throw NegIndex(index);
        }
        if (index >= len_) {
            throw OutOfRange(index);
        }
        if (p_ == NULL) {
            throw MerroryException();
        }
        return p_[index];
    }
    
    class NegIndex:public exception{
    public:
        NegIndex(int index) throw():i(index){
        }
        const char* what() const throw(){
            static char buf[100];
            sprintf(buf, "负小标异常 %d",i);
            return buf;
        }
    private:
        int i;
    };
    
    class OutOfRange:public exception{
    public:
        OutOfRange(int index) throw():i(index){
        }
        const char* what() const throw(){
            static char buf[100];
            sprintf(buf, "小标越界异常 %d",i);
            return buf;
        }
    private:
        int i;
    };
    
    class MerroryException:public exception{
    public:
        const char* what() const throw(){
            static char buf[100];
            sprintf(buf, "内存异常异常");
            return buf;
        }
    private:
    };
    
    
//    class OutOfRange
    
private:
    int* p_;
    int len_;
};

int main(int argc, const char * argv[]) {
#if 0
//    set_terminate(beforedie);
//    func();
    set_unexpected(func3);
    try {
//        f2();
        f3(10);
    } catch (int e) {
        cout << "int " << e << endl;
    }catch (double e) {
        cout << "double " << e << endl;
    }catch(...){
        cout << "exception" << endl;
    }
    cout << "我还会回来的" << endl;

    try {
        double* p = new double[~0];
        cout << p << endl;
    } catch (exception& e) {
        cout << e.what() << endl;
    }
    
    cout << "oh yeah" << endl;
#endif
    A x(10);
    x[0] = 5;
    x[3] = 10;
    x[8] = 20;
    cout << x[3] * x[0] * x[8] << endl;
    cout << x[-5] << endl;
    
    return 0;
}
