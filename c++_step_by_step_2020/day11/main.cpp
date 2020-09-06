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
}

int main(int argc, const char * argv[]) {
    
    testLanbada();
    
    return 0;
}
