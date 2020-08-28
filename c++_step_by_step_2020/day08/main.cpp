//
//  main.cpp
//  day08
//
//  Created by yhp on 2020/8/27.
//  Copyright © 2020 none. All rights reserved.
//

#include <iostream>

using namespace std;

/**
 -------------------------
 对象型参数和返回值
 1,使用对象类型作为函数的参数或者返回值,可能产生一些不必要的中间对象
 -------------------------
 匿名对象(临时对象)
 1,没有变量名,没有被指针指向的对象，用完后马上调用析构
 -------------------------
 隐式构造
 1,c++中存在隐式构造的现象:某些情况下,会隐式调用单参数的构造函数
 2,explicit关键字,静止隐式构造
 -------------------------
 */
class Car {
    
public:
    Car(){
        cout << "Car(int) -" << this << endl;
    }
    
    Car(const Car& car){
       cout << " Car(const Car& car) -" << this << endl;
    }
    
    ~Car(){
        cout << "~~Car() -" << this << endl;
    }
    void run(){
        cout << "run()" << endl;
    }
};

void test(Car& car){
    
}

Car test2(){
    Car car;
    return car;
}

Car test3(){
    return Car();
}

class Person {
    int m_age;
public:
    Person(){
        cout << "Person() -" << this << endl;
    }
    
   explicit  Person(int age):m_age(age){
        cout << "Person(int) -" << this << endl;
    }
    
    Person(const Person& person){
        cout << "Person(const Person& person) -" << this << endl;
    }
    
    ~Person(){
        cout << "~~Person()-" << this << endl;
    }
    void display(){
        cout << "display()- age is " << this->m_age << endl;
    }
};
void testCar(void){
//   平台不一样,结果不一样
    Car car;
    car = test3();
    test(car);
    Car car2;
    car2 = test2();
    Car car3 = test2();
//    匿名对象
    Car().run();
}
void test4(Person person){
    
}
// 隐式构造
//Person test5(){
//    return 40;
//}

void testPerson(void)
{
    Person p1;
    Person p2(10);
    Person p3 = p2;
//  隐式构造
//    Person p4 = 20;//  Person p4(20);
//    test4(30);
//    test5();
//    p1 = 60;
    
}

int main(int argc, const char * argv[]) {
    
    testPerson();
    
    return 0;
}
