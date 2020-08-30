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
 编译器自动生成的构造器
 1,c++的n编译器在某些特定的情况下，会s给类自动生成无惨的构造函数
 2,成员变量在声明的同时进行了初始化
 3,有虚继承其他类
 4,包含了对象类型的成员,且这个成员有构造函数(编译器生成或自定义)
 5,父类有构造函数
 总结
 对象创建后,需要做一些额外的操作时(比如内存操作,函数调用,编译器一般会c
 为其生成无惨的构造函数
-------------------------
 友元---友元函数和友元类
 1,如果将函数A（非成员函数)声明为类C的友元函数,那么在函数A内部能访问C类内部的s所有成员
 2,如果将类A声明为类C的友元类,那么在类A的所有成员函数的内部都能直接访问类C对象的所有成员
 -------------------------
 内部类
 1,如果将类A定义在类C的内部,那么类A就是一个内部类(嵌套类)
 2,支持public，protexted private权限
 3,成员函数可以直接访问其外部类对象的所有成员(反过来则不行)
 4,成员函数可以直接不带类名,对象名访问外部类的static成员
 5,不会影响外部类内存布局
-------------------------
局部类
 1,在一个函数内部定义的类,成为局部类
 2,作用域仅局限于所在的函数内部
 3,其所有的成员必须在类内部,不允许定义static成员变量
 
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
class Car2 {
public:
    int m_price;
    Car2(){
        
    }
};

class Person2 {
public:
    int m_price = 5; // Person(){m_price = 5;}编译器默认生成
    virtual void run(){
        
    }// virtual 编译器会默认生成构造函数
    Car2 car;
};
// 编译器会生成默认构造函数
class Student: virtual public Person2 {
public:
    int m_score;
};

class Point {
    friend Point add(Point p1,Point p2);
    friend class Math;
private:
    int m_x;
    int m_y;
public:
    int getX(){
        return m_x;
    }
    int getY(){
        return m_y;
    }
    Point(int x,int y):m_x(x),m_y(y){
        
    }
    void display(){
        cout << "(" << m_x << "," << m_y << ")" <<endl;
    }
};

class Math{
    
public:
    Point add(Point p1,Point p2){
        return Point(p1.m_x + p2.m_x, p1.m_y + p2.m_y);
    }
};

Point add(Point p1,Point p2){
    return Point(p1.m_x + p2.m_x, p1.m_y + p2.m_y);
}

class Person3 {
private:
    int m_age;
    static int m_score;
    static void test(){
        
    }
public:
    class Car{
        int m_price;
        void run(){
            Person3 person;
            person.m_age = 10;
//            Person3::test();
            test();
            m_score = 20;
        }
    };
};

void testClass(){
    static int age = 10;
    // 句柄类
    class Car {
        void run() {
            age = 50;
        }
    };
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
//    Person3::Car car;
}
void testFriend(void)
{
    Point p1(20,30);
    Point p2(30,50);
    Point p3 = add(p1,p2);
    p3.display();
    Math m;
    Point p4 = m.add(p1,p2);
    p4.display();
}

int main(int argc, const char * argv[]) {
    
    testFriend();
    
    return 0;
}
