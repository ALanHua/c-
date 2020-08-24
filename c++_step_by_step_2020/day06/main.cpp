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
 静态成员
 1,存储在数据段(全局区,类似于全局变量）,整个程序运行过程中只有一份内存
 2,可以通过对象.静态成员变量,对象指针->静态成员,类名::静态成员变量
 3,对比全局变量,它可以设定访问权限(private,protected,public)
 4,必须初始化，必须在类外面初始化，初始化不能带static，如果类的声明和实现分离,它必须在.cpp里实现
 静态成员函数
 1,函数内部不能使用this指针(this指针只能在非静态成员函数使用)
 2,不能是虚函数(虚函数只能是非静态成员函数)
 3,内部不能访问非静态成员变量\函数，只能访问静态成员变量\函数
 4,非静态成员函数内部可以访问静态成员变量\函数
 5,构造析构函数不能是静态
 6.声明和实现分离,实现不要带static
 ---------------------------
 ds --- data segment
 
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

// 多继承的应用
class JobBaomu {
public:
    virtual void clean() = 0;
    virtual void cook() = 0;
};

class JobTeacher {
public:
    virtual void playfootball() = 0;
    virtual void playbaseball() = 0;
};

class Student3 : public JobBaomu,public JobTeacher{
    int m_score;
public:
    void clean(){
        
    }
    
    void cook(){
        
    }
    
    void playfootball(){
        
    }
    
    void playbaseball(){
        
    }
};

class Worker3 : public JobBaomu,public JobTeacher{
    int m_salary;
    void clean(){
    }
    
    void cook(){
        
    }
    
    void playfootball(){
        
    }
    
    void playbaseball(){
        
    }
};
//---------------------------------
class Car {
public:
    static int m_price;// 相当于全局变量
    static void run(){
        cout << "run()" << endl;
    }
    void test(){
        run();
        m_price = 10;
    }
};
// 静态成员变量必须放在类外面初始化的
int Car::m_price = 0;

//-----------------------
class Person2{
public:
    static int m_age;
};
int Person2::m_age = 0;
class Student4: public Person2 {
public:
    
};

class Car3 {
private:
    static int ms_count;
public:
    Car3(){
        // 严格来说这里要考虑多线程，这个最好使用原子类型
        ms_count++;
    }
    ~Car3(){
        ms_count--;
    }
// 可以通过类名调用
    static int getCount(){
        return ms_count;
    }
};
int Car3::ms_count = 0;

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

void test2(void)
{
    Car car1;
    car1.m_price = 100;
    car1.run();
    Car car2;
    car2.m_price = 200;
    Car car3;
    car3.m_price = 300;
    cout << Car::m_price  << endl;
    
    Car* p = new Car();
    p->m_price = 400;
    p->run();
    delete p;
    cout <<  Car::m_price  << endl;
    
    cout << &Student4::m_age << endl;
    cout << &Person2::m_age << endl;
    
    Car3 car4;
    cout << Car3::getCount() << endl;
    
}

int main(int argc, const char * argv[])
{
    test2();
    return 0;
}
