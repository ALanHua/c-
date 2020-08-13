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
 1,命名空间不影响内存布局
 2,多个地方定义命名空间，它会合并
------------------------------------
 继承
 1,c++ 没有基类
 2，从父类继承过来的成员变量会排在内存前面
------------------------------------
 成员访问权限
 1,private 私有的，只能当前类内部可以访问（class 默认）
 2,protected 子类内部,当前n类部可以访问
 3,public  公共的，任何地方都可以访问（struct默认）
 4,子类内部访问父类成员的权限，是以下2项<成员变量的权限和上一层的继承方式>中权限最小的那个
 5,不影响内存布局
 6,class默认是private继承，struct默认是public继承
 7,子类一般使用public继承
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
namespace DAY04 {
    class Person2 {
    private:
        int m_age;
    public:
        Person2();
        ~Person2();
        void setAge(int age);
        int getAge();
    };
}
//--------实现----------------
namespace DAY04 {
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
    // 命名空间可以嵌套
    namespace DAY04_01{
        int m_age;
    }
}
// 会合并到上一个里面
namespace DAY04 {
    int g_no;
}

void func(){
    
}
//-------------------------
struct Human {
private:
    int m_age;
public:
    void setAge(int age){m_age = age;}
    int getAge(){return m_age;}
    void run(){}
};

struct Student : public Human{
    int m_score;
    void study(){}
};

struct GoodStudent : public Student{
    int m_salary;
    void work(){}
};

//-------------------------
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
//  不需要加命名空间前缀
    using namespace DAY04;
    g_age = 30;
    DAY04::func();
    // 全局命名空间,所有命名空间都嵌套在全局b命名空间中
    ::func();
    ::DAY04::func();
//
    Person2 person;
}

void testClass(void){
    
}

int main(int argc, const char * argv[])
{
    testNamespace();
    return 0;
}
