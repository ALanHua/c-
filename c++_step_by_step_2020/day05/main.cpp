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
 2,子类会默认会调用父类的构造函数
 3,如果子类的构造函数显示的调用父类的有参构造函数，父类的无惨构造函数不会调用
 4,如果父类没有的无惨构造函数，子类必须显示的调用父类的有参构造函数
 --------------------------------
 多态
 1,clas(默认是private)必须是public继承才能让父类指针访问子类对象
 2,默认情况下，编译器只会根据指针类型调用对应的函数，不存在多态
 3,同一个操作作用于不同的对象，可以有不同的解释，产生不同的执行结果
 4,通过虚函数(virtual function)实现
 5,运行时,可以识别出真正的对象类型,调用对应子类中的函数
 
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
        cout << "Person::Person()" << endl;
    }
    
    Person2(int age,int height){
        m_age    = age;
        m_height = height;
    }
};

class Person3 {
    int m_age;
public:
    
    Person3(int age) :m_age(age){
        cout << "Person::Person(int age)" << endl;
    }
    
    ~Person3(){
        cout << "Person::~Person()" << endl;
    }
};

class Student: Person3 {
//    int m_no;
    int m_score;
public:
    Student(int age,int score):m_score(score),Person3(age){
        // call Person3::Person3()
        cout << "Stdudet:Stdudet(int age,int no)" << endl;
    }
    
    ~Student(){
        cout << "Stdudet:~Stdudet()" << endl;
        // call Person3::~Person3()
    }
};

class Person4 {
public:
    int m_age;
};

class Student2: public Person4 {
    int m_score;
};

struct Animal {
    int m_age;
    virtual void speak(){
        cout << "Animal::speak()" << endl;
     }
    // 子类默认也是虚函数
     virtual void run(){
        cout << "Animal::run()" << endl;
     }
};

struct Dog : Animal{
//    重写(override)
    void speak(){
        cout << "Dog::speak()" << endl;
    }
    void run(){
        cout << "Dog::run()" << endl;
    }
};
struct Cat :Animal{
    int m_life;
    
    void speak(){
        // 调用父类里的函数
        Animal::speak();
        cout << "Cat::speak()" << endl;
    }
    void run(){
        cout << "Cat::run()" << endl;
    }
};

struct Pig :Animal{
    int m_life;
    
    void speak(){
        cout << "Pig::speak()" << endl;
    }
    void run(){
        cout << "Pig::run()" << endl;
    }
};

struct WhiteCat :  Cat{
    void speak(){
        cout << "WhiteCat::speak()" << endl;
    }
    void run(){
        cout << "WhiteCat::run()" << endl;
    }
};

void liu(Animal* p)
{
    p->speak();
    p->run();
}

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
//----------------
    Student student(10,20);
//-----------------
    // 父类指针指向子类对象
    Person4* p = new Student2();
    p->m_age = 10;
    cout <<  p->m_age << endl;
}

void testPolymorphic(void){
    
    Dog* d = new Dog();
    Cat* c = new Cat();
    Pig* p = new Pig();
    liu(d);
    liu(c);
    liu(p);
    delete d;
    delete c;
    delete p;
// ------------------------------
    Animal* cat = new Cat();// 成员变量默认初始化为0
    cat->m_age = 20;
    cat->speak();
    cat->run();
    cout << sizeof(Animal) << endl;
    delete cat;
    
    Animal* cat1 = new WhiteCat();
    cat1->speak();
    cat1->run();
    delete cat1;
    
}

int main(int argc, const char * argv[])
{
    testPolymorphic();

    return 0;
}
