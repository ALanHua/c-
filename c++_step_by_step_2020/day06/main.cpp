//
//  main.cpp
//  day06
//
//  Created by yhp on 2020/8/16.
//  Copyright © 2020 none. All rights reserved.
//

#include <iostream>

using namespace std;

/**
 虚析构函数
 1,只要有父类指针指向子类对象的时候即多态的时候父类析构函数需要定义为虚析构
 --------------------------
 纯虚函数
 1,没有函数体且初始化为0的虚函数，用来定义接口规范
--------------------------
 抽象类
 1,含有存虚函数的类，不可以实例化(不可以创建对象)
 2,抽象类也可以包含非纯虚函数，成员变量
 3,如果父类时抽象类，子类没有完全实现纯虚函数，那么这个子类就是抽象类
--------------------------
 多继承
 -- 虚函数
    1,如果子类继承的多个父类y都有虚函数，那么子类对象就会产生对应的多张虚表
 -- 同名函数
 -- 同名成员变量
 -- 菱形继承
    1,虚继承可以解决菱形继承带来的问题
--------------------------
 */

struct Animal2 {
    int m_age;
    void speak(){
        cout << "Animal::speak()" << endl;
    }
    void run(){
        cout << "Animal::run()" << endl;
    }
    
    Animal2(){
//        cout << "Animal::Animal()" << endl;
    }
    // 虚析构函数
   virtual ~Animal2(){
//        cout << "Animal::~Animal()" << endl;
    }
};

struct Cat2 : Animal2{
    void speak(){
        cout << "Dog::speak()" << endl;
    }
    void run(){
        cout << "Dog::run()" << endl;
    }
    
    Cat2(){
//        cout << "Cat::Cat()" << endl;
    }
    ~Cat2(){
//        cout << "Cat::~Cat()" << endl;
    }
};

struct Animal {
    int m_age;
//   存虚函数
    virtual void speak() = 0;
    virtual void run() = 0;
};

// 依然是抽象类
struct Dog : Animal{
    void run(){
        cout << "Dog::run()" << endl;
    }
};

struct Hashiqi: Dog {
    void speak(){
        cout << "Hashiqi::speak()" << endl;
    }
    void run(){
        cout << "Hashiqi::run()" << endl;
    }
};

struct Student {
    int m_score;
    Student(int score):m_score(score){
        
    }
    void study(){
        cout << "Student::study - score " << m_score <<endl;
    }
    void eat(){
        cout << "Student::eat " <<endl;
    }
};

struct Worker {
    int m_salary;
    Worker(int salary):m_salary(salary){
        
    }
    void work(){
        cout << "Worker::work - salary " << m_salary <<endl;
    }
    void eat(){
         cout << "Worker::eat " <<endl;
    }
};

struct Undergradute: Student,Worker {
    int m_grade;
    
    Undergradute(int score,int salary,int grade)
    :m_grade(grade),Student(score),Worker(salary){
        
    }
    void play(){
        cout << "Udergradute::play - salary " << m_grade <<endl;
    }
    
    void eat(){
        cout << "Udergradute::eat " <<endl;
    }
};
// 菱形继承
struct Person {
    int m_age = 1;
};

/**
 内存布局
 | 虚表指针  8
 | m_score  4
 | m_age    4
 */
struct Student2: virtual Person {
    int m_score = 2;
};

/**
 内存布局
 | 虚表指针   8
 | m_salary  4
 | m_age     4
 */
struct Worker2: virtual Person {
    int m_salary = 3;
};

/**
 内存布局
 | 内存对齐    8
 ---Student2----
 | 虚表指针    8
 | m_score   4
 ---Worker2----
 | 虚表指针    8
 | m_salary  4
  ---Undergradute2----
 | m_grade   4
  ---Person----
 | m_age     4
 */
struct Undergradute2: Student2,Worker2 {
    // m_age 只存在一份
    int m_grade = 4;
};

void test(void)
{
    Animal2* cat = new Cat2();
    cat->speak();
    delete cat;
    Undergradute ug(100,2000,4);
    ug.study();
    ug.work();
    ug.play();
    ug.Student::eat();
    ug.Worker::eat();
    ug.eat();
    Undergradute2 ug2;
    cout << sizeof(ug2) << endl;
}

int main(int argc, const char * argv[]) {
   
    
    test();
    
    return 0;
}
