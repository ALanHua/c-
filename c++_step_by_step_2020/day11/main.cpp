//
//  main.cpp
//  day11
//
//  Created by yhp on 2020/9/6.
//  Copyright © 2020 none. All rights reserved.
//

#include <iostream>

using namespace std;

/*
 ---------------------
 lambda表达式
 1,本质上就是函数
 2,完整结构 [capture list](params list) mutable exception -> return type(function type)
 ---------------------
 异常
 1,异常是一种在程序运行过程中可能会发生的错误(比如内存不够)
 2,throw异常后,会在当前函数中查找匹配的catch,找不到就终止
   当前函数代码,在上一层函数中查找,如果最终都找不到匹配的catch，整个程序就会终止
 3,为了增强可读性和方便团队协作,如果函数内部可能s会抛出异常
   建议函数声明一下异常类型
 ---------------------
 标准异常
 
 ---------------------
 */

void func(){
    cout << "func()" << endl;
}

int add(int v1,int v2){
    return v1 + v2;
}

int sub(int v1,int v2){
    return v1 - v2;
}

int multiple(int v1,int v2){
    return v1 * v2;
}

int divide(int v1,int v2){
    return v1 / v2;
}

int exec(int v1,int v2,int(*func)(int,int)){
    return func(v1,v2);
}

void testLanbada()
{
    // lambada 表达式
//    void(*p)() = []{
//        cout << "func()" << endl;
//    };
    
    auto p = []{
        cout << "func()" << endl;
    };
    p();
    
//    auto p1 = [](int a,int b) -> int{
//        return a + b;
//    };
    auto p1 = [](int a,int b){
        return a + b;
    };
    cout << p1(10,20) << endl;
    
    cout << exec(30,20,add) << endl;
    cout << exec(30,20,sub) << endl;
    cout << exec(30,20,multiple) << endl;
    cout << exec(30,20,divide) << endl;
    // lambada
    cout << exec(30,20,[](int v1,int v2){
        return v1 + v2;
    }) << endl;
    
    cout << exec(30,20,[](int v1,int v2){
        return v1 - v2;
    }) << endl;
    
    cout << exec(30,20,[](int v1,int v2){
        return v1 * v2;
    }) << endl;
    
    cout << exec(30,20,[](int v1,int v2){
        return v1 / v2;
    }) << endl;
    
//  变量捕获
    int a = 10;
    int b = 20;
    auto func = [&a,b] {
//   auto func = [=] {// 隐式捕获
        cout << a << endl;
        cout << b << endl;
    };
    a = 50;
    func();
    
    auto func1 = [&a]{
        cout << a << endl;
        a++;
    };
    
    auto func2 = [a] ()mutable{
        a++;// 内部变量
        cout << "lambada: " << a << endl;
    };
    
    func1();
    cout << a << endl;
    func2();
    cout << a << endl;
//------------- c++ 14------------
    // 1，泛型lambada表达式
    auto func3 = [](auto v1,auto v2){
        return v1 + v2;
    };
    cout << func3(10,20.5) << endl;
    // 2,对捕获的变量进行初始化
    int c;
    auto func4 = [c = 10](){
        cout << c << endl;
    };
    func4();
    cout << c << endl;// 未初始化
    
}

void test01()
{
// ---------c++17-----------------
    if (int a = 10;a > 10) {
        a = 1;
    }else if (int b = 20; a > 5 && b > 10){
        b = 2;
        a = 2;
    }else if(0){
        b = 3;
        a = 3;
    }else{
        b = a;
        a = 4;
    }
}

void testException01(){
    for (int i = 0; i < 99999; i++) {
        try {
            int *p = new int[99999999999];
            /*
             下面不会在执行
             .......
             ........
             .......
             */
        } catch (...) {// 捕捉所有异常
            cout << "内存不够用" << endl;
            break;
        }
    }
}

void func3() throw(){// 不抛出任何异常
    
}

int divide2(int v1,int v2)throw(const char*){// 声明抛出异常类型
    if (v2 == 0) {
        throw "不能除以0";
    }
    return v1 / v2;
}

void testException02(){
    try {
        int a = 10;
        int b = 0;
        cout << divide2(a,b) << endl;
    } catch (const char* exception) {
        cout << "产生异常 const char*:" << exception << endl;
    }catch (int exception){
        cout << "产生异常 int :" << exception << endl;
    }
    
}

// 自定义异常l类型
class Exception {
public:
    virtual const char* what()const = 0;
};

class DivideException: public Exception {
public:
    const char* what()const{
        return "不能除以0";
    }
};

class AddException: public Exception {
public:
    const char* what()const{
        return "加法有问题";
    }
};

int divide3(int v1,int v2){// 声明抛出异常类型
    if (v2 == 0) {
        throw DivideException();
    }
    return v1 / v2;
}

void testException03(){
//    try {
//        int a = 10;
//        int b = 0;
//        cout << divide3(a,b) << endl;
//    } catch (DivideException exception) {
//        cout << "产生异常 DivideException()" << exception.what() << endl;
//    }catch (AddException exception){
//        cout << "产生异常 AddException()" << endl;
//    }
    
    try {
        int a = 10;
        int b = 0;
        cout << divide3(a,b) << endl;
    } catch (const Exception& exception) {
        cout << "产生异常 DivideException()" << exception.what() << endl;
    }
}

int main(int argc, const char * argv[]) {
    
    testException03();
    
    return 0;
}
