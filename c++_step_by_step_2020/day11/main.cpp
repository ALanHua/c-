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

int main(int argc, const char * argv[]) {
    
    test01();
    
    return 0;
}
