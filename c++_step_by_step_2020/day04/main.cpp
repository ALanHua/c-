//
//  main.cpp
//  day04
//
//  Created by yhp on 2020/8/11.
//  Copyright © 2020 none. All rights reserved.
//

#include <iostream>

using namespace std;

/*
 构造函数的特点
 1,函数名与类名一样，没有返回值
 2,可以有参数，可以重载
 3,一旦定义了构造函数，必须用其中一个自定义的构造函数来初始化对象
 4,通过malloc分配对象不会调用构造函数
 5,在某些特定情况下，编译器才会为类生成g空的无惨构造函数
 */
struct Person {
    int m_age;
    int m_money;
    
    Person(){
        m_age = 0;
        cout << "Person()" << endl;
    }
    
    Person(int age){
        m_age = age;
        cout << "Person(int age)" << endl;
    }
   
    Person(int age,int money){
        m_age = age;
        m_money = money;
        cout << "Person(int age,int money)" << endl;
    }
    
    void display(){
        cout << "age = " << m_age
            << ", money = " << m_money << endl;
    }
};

void testPerson(void)
{
    Person person;
    person.display();
    Person person2(20);
    person2.display();
    Person person3(30);
    person3.display();
//  堆
    Person* p = new Person;
    delete p;
}

int main(int argc, const char * argv[])
{

    
    return 0;
}
