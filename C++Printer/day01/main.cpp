//
//  main.cpp
//  day01
//
//  Created by yhp on 2018/10/16.
//  Copyright © 2018 none. All rights reserved.
//

#include <iostream>
#include <string>
// 命名空间解决名字冲突的问题
// 匿名名字空间 -- 全局名字空间 ::var = 123 / var = 123
// c++ 结构体还可以是函数，甚至还可以是类型
// void* 类型 严格限制不能赋值给其他地址类型 c++ 强类型语言
using namespace std;
namespace andy {
    struct Student{
        char name[20];
        int  age;
        void show(){
            cout << name << " " << age  << " "<< "c++ learn" << endl;
        }
    };
    enum Color {
      RED,GREEN,BLUE
    };
//  函数重载
    void show(int n)
    {
        cout << "整数" << n << endl;
    }
    
    void show(double n)
    {
        cout << "小数" << n << endl;
    }
    void show(int n,int m)
    {
        cout << "一对整数" << n  <<"," << m << endl;
    }

    struct Person {
        char name[20];
        char gender;
    };
    
    void show(Person p)
    {
        cout << "一个人" << p.name <<"," << p.gender << endl;
    }
}

/** 强制类型转换
 1，static_cast<类型>(数据)用于数值类型之间y以及void* 和 其他*
 2，reinterpret_cast<类型>(数据)用于数值类型或者地址类型之间，或者地址类型相互之间
 3，const_cast<T*>(T 常量地址) 去掉const限制
 4，dynamic_cast 面向对象
 */

/**
 1,c 函数默认返回int 类型，c++ 作废
 2,c 空参数表示参数个数随意，c++中只表示无惨，函数在调用前必须声明或者定义
 */

int main(int argc, const char * argv[]) {
    
    andy::Student s1 = {
        "andy",18
    };
    
    using namespace andy;
    Student s2;
    strcpy(s2.name, "alan");
    s2.age = 20;
    
    s1.show();
    s2.show();
    
//  匿名联合
    union {
        int x;
        char y[4];
    };
    
    x = 0x61626364;
    cout << hex << showbase << x << endl;
    y[1] = '0';// 0x30
    cout << hex << showbase << x << endl;
    
    Color c;
    c = GREEN;
    cout << c << endl;
    void*p = &c;
    Color* q;
//    q = p; 无法编译
    /**
     强制类型转换
     */
    q = (Color*)p;
    cout << *q << endl;
    
    int a = static_cast<int>(123.45);
    cout << dec << a << endl;
    int b = 100;
    void* p1 = &b;
    int* q1 = static_cast<int*>(p1);
    char* r = reinterpret_cast<char*>(q1);
    cout << "r=" << r << endl;
    const int c1 = b;
    cout << "c1=" << c1 << endl;
    *const_cast<int*>(&c1) = 200;
    cout << "c1=" << c1 << endl;
    
    show(123);
    Person fj = {
      "凤姐",'M'
    };
    show(fj);
    show(45.6);
    show(10, 20);
    
    return 0;
}
