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
 ------------------------
 构造函数之间相互调用
 1,构造函数调用构造函数必须在初始化列表
 2,
 --------------------------------
 */

int myAge(int age){
//    cout << "myAge()" << endl;
    return age;
}

int myHeight(int height){
//    cout << "myHeight()" << endl;
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

struct Person2 {
    int m_age;
    int m_height;
    
    Person2() : Person2(0,0){
        /*
        不是调用构造函数，只是创建了一个临时的Person2对象
        Person2(10,20)
         */
    }
    
    Person2(int age,int height){
        m_age    = age;
        m_height = height;
    }
};

void testPerson(void){
    Person person(10,100);
    cout << person.m_age << endl;
    cout << person.m_height << endl;
    Person person2;
    Person person3(17);
//----------------
    Person2 person4;
    cout << person4.m_age << endl;
    cout << person4.m_height << endl;
    
}

int main(int argc, const char * argv[])
{
    testPerson();

    return 0;
}
