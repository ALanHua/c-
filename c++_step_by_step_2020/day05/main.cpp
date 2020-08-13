//
//  main.cpp
//  day05
//
//  Created by yhp on 2020/8/13.
//  Copyright © 2020 none. All rights reserved.
//

#include <iostream>
using namespace std;

/**
 初始化列表
 1,初始化顺序只跟成员变量的定义顺序有关
 2,只能用在构造函数
 3,如果函数声明和实现是分离的，初始化列表只能卸载函数实现中
 4,默认参数只能写在声明里
 --------------------------------
 */

int myAge(int age){
    cout << "myAge()" << endl;
    return age;
}

int myHeight(int height){
    cout << "myHeight()" << endl;
    return height;
}

struct Person {
    int m_age;
    int m_height;
//    Person(int age,int height){
//        m_age = age;
//        m_height = height;
//    }
    //  初始化列表，本质就是上面的操作
    Person(int age = 0,int height = 0);
};

Person::Person(int age,int height)
    :m_age(myAge(age)),m_height(myHeight(height)){}


void testPerson(void){
    Person person(10,100);
    cout << person.m_age << endl;
    cout << person.m_height << endl;
    Person person2;
    Person person3(17);
}

int main(int argc, const char * argv[])
{
    testPerson();

    return 0;
}
