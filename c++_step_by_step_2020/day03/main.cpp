//
//  main.cpp
//  day03
//
//  Created by yhp on 2020/8/6.
//  Copyright © 2020 none. All rights reserved.
//

#include <iostream>

using namespace std;

/*
 class 和 struct的区别
 1 --- struct的默认成员权限是public
        class的默认权限是private
 2 --- 开发中尽量使用class
 ------------------------
 编程规范：
 1--
 全局变量: g_
 成员变量: m_
 静态变量: s_
 常量:    c_
 2--
 使用驼峰标识
 -----------------------
 this指针
 1，this指针存储函数的调用者的地址
 2，this指向了函数的调用者
 -----------------------
 代码区
 1，调用函数的时候需要分配额外的存储空间来存储变量
 2，代码区是只读的，在栈空间分配一段连续的空间给代码区里函数使用
 */

//class Person{
////    成员函数
//    int age;
////    成员函数（方法）
//    void run(){
//        cout << "Person run()" << endl;
//    }
//};

struct Person{
    //    成员函数
    int m_id;
    int m_age;
    int m_height;
    //    成员函数（方法）
    void run(){
        cout << "Person run() " << m_age << endl;
    }
    
    void display(){
        cout << "id = " << m_id
             << ", age =" << m_age
             <<",height =" << m_height << endl;
    }
};

class Car{
public:
    int m_price;
    void run(){
//      this指针存储函数的调用者的地址
//      this指向了函数的调用者
        cout << "Car run()->" << this->m_price << endl;
    }
};

// 封装
struct Person2 {
private:
    int m_age;
public:
    void setAge(int age){
        if(age < 0){
            m_age = 1;
        }else{
            m_age = age;
        }
    }
    
    int getAge(){
        return m_age;
    }
};

void testPerson()
{
    //  利用类来创建对象
    Person person;
    person.m_age = 10;
    person.run();
    cout << sizeof(person) << endl;
    Person* p = &person;
    p->m_age = 20;
    p->run();
    // add
    person.m_id = 1;
    person.m_age = 2;
    person.m_height = 3;
    person.display();
    cout << "&person      " << &person << endl;
    cout << "&person.m_id " << &person.m_id << endl;
    cout << "&person.m_age " << &person.m_age << endl;
    cout << "&person.m_height " << &person.m_height << endl;
    p->m_id = 20;
    p->m_age = 39;
    p->m_height = 40;
    p->display();
    // 作业
    p = (Person*)&person.m_age;
    p->m_id = 100;
    p->m_age = 200;
    p->display();
//    中断：interupt
//    0xcc ->int3 起到断点的作用
}

void testCar(void)
{
    Car car;
    car.m_price = 10;
    car.run(); // call 函数地址 内存中只有一份
    
    Car car1;
    car1.m_price = 30;
    car1.run(); // call 函数地址 内存中只有一份
    
    Car car2;
    car2.m_price = 50;
    car2.run(); // call 函数地址 内存中只有一份
    
}

void testPerson2(void)
{
    Person2 person;
    person.setAge(30);
    cout << person.getAge() << endl;
}

void testMemory(void)
{
//    int* p = (int*)malloc(4);
//    *p =10;
//    malloc / free
    char* p = (char*)malloc(4);
    memset(p, 0, sizeof(char)*4);
    *p = 10;
    *(p + 1) = 11;
    *(p + 2) = 12;
    *(p + 3) = 13;
    free(p);
//    new / delete
    int* p1 = new int;
    *p1 = 10;
    delete p1;
    char* p2 = new char;
    delete p2;
//  new[] / delete[]
    char* p3 = new char[4];
    *p3 = 10;
    *(p3 + 1) = 21;
    *(p3 + 2) = 22;
    *(p3 + 3) = 23;
    delete [] p3;
//  内存初始化
    int* p4 = new int();
    int* p5 = new int(5);
    cout << *p4 << endl; // 0
    cout << *p5 << endl; // 5
//  数组
    int* p6 = new int[3]();  // 初始化0
    int* p7 = new int[3]{};  // 初始化0
    int* p8 = new int[3]{5}; // 首元素初始化5，其他初始化为0
    delete p4;
    delete p5;
    delete[] p6;
    delete[] p7;
    delete[] p8;
}

int main(int argc, const char * argv[])
{
    testMemory();
    return 0;
}
