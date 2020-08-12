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
------------------------------------
 成员变量初始化
 1,如果自定义了构造函数，除了全局区，其他内存空间成员变量默认不会初始化
------------------------------------
 析构函数:在对象销毁的时候自动调用，一般完成对象的清理工作
 特点:
 1,函数名以~开头,与类同名，无返回值(void都不能写)，无惨，不可重载，有且只有一个析构函数
 2,通过malloc分配对象，调用free不会调用析构函数
------------------------------------
 构造和析构函数的权限必须是oublic
 ------------------------------------
 命名空间:解决命名冲突的问题
 
 */
struct Car {
    int m_price;
    Car(){
        m_price = 0;
        cout << "Car::Car()" << endl;
    }
    
    ~Car(){
        cout << "Car::~Car()" << endl;
    }
};

struct Person {
private:
    int m_age;
    int m_money;
    Car* m_car;
public:
    Person(){
        // 初始化成员变量
        memset(this, 0, sizeof(Person));
        m_car = new Car();
        cout << "Person::Person()" << endl;
    }
    
    Person(int age){
        m_age = age;
        m_car = new Car();
        cout << "Person(int age)" << endl;
    }
   
    Person(int age,int money){
        m_age = age;
        m_money = money;
        m_car = new Car();
        cout << "Person(int age,int money)" << endl;
    }
//   一个Person对象销毁的象征
    ~Person(){
        cout << "Person::~Person()" << endl;
        delete m_car;
    }
    
    void display(){
        cout << "age = " << m_age
            << ", money = " << m_money << endl;
    }
};
/*
 类实现和定义分离
 */
//---------声明---------------
class Person2 {
private:
    int m_age;
public:
    Person2();
    ~Person2();
    void setAge(int age);
    int getAge();
};
//--------实现----------------
Person2::Person2(){
    m_age = 0;
}
Person2::~Person2(){
    
}
void Person2::setAge(int age){
    m_age = age;
}

int Person2::getAge(){
    return m_age;
}
//------------------------
namespace DAY04 {
    // 全局函数
    int g_age;
    // 函数
    void func(){
        
    }
    class Person {
        int m_age;
        int m_money;
    };
}
void testPerson(void)
{
    // 栈空间成员变量未初始化
    Person person;
    person.display();
    Person person2(20);
    person2.display();
    Person person3(30);
    person3.display();
//  堆
    Person* p = new Person;
    Person* p1 = new Person();
    Person* p2 = new Person(30);
    delete p;
    delete p1;
    delete p2;
//    Person person4(); 这样写是函数声明，不是创建对象
}

void testNamespace(void){
    DAY04::Person person4;
    cout << sizeof(person4) << endl;
    DAY04::g_age = 20;
    DAY04::func();
}
int main(int argc, const char * argv[])
{
    testNamespace();
    return 0;
}
