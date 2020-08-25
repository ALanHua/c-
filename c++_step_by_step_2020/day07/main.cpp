//
//  main.cpp
//  day07
//
//  Created by yhp on 2020/8/24.
//  Copyright © 2020 none. All rights reserved.
//

#include <iostream>
using namespace std;
/**
------------------------
 单例模式:设计模式的一种,保证某个类只创建一个对象
 1,构造函数和析构函数私有化
 2,定义一个私有static成员变量指向y唯一的那个单例对象
 3,提供一个公共的访问单例对象的接口
------------------------
 const 修饰的对象不能修改成员变量
 const 成员变量
 1,必须要初始化(类内部初始化),可以在声明的时候直接初始化赋值
 2,非静态成员变量可以在构造函数初始化列表中初始化
 cost 成员函数
 1,cost关键字写在参数列表后面,函数的声明和实现必须带有const
 2,内部不能修改非静态的成员变量
 3，内部只能调用const修饰的成员函数和静态成员函数
 4,非const成员函数可以调用const成员函数
 5,const成员函数和非const成员函数构成重载
 6,非const对象(指针)优先调用非const成员函数
 7,const对象(指针)只能调用const成员函数
------------------------
 引用类型成员
 1,引用类型成员变量必须初始化(不考虑static情况)
------------------------
 copy构造函数
 1,当利用自己存在的对象创建一个新对象时(类似于拷贝)，就会y调用新对象的构造函数进行初始化
 2,拷贝构造函数的格式是固定的，接收一个const引用作为参数
------------------------
 */
class Rocket {
private:
    static Rocket* ms_rocket;// 内存使用灵活
    Rocket(){}
    ~Rocket(){}
public:
    static Rocket* shareRocket(){
        // 多线程安全问题
        if (ms_rocket == NULL) {
            ms_rocket = new Rocket();
        }
        return ms_rocket;
    }
    static void deleteRocket(){
        // 多线程安全问题
        if (ms_rocket != NULL) {
            delete ms_rocket;
            ms_rocket = NULL;
        }
    }
    void run(){
        cout << "run()" << endl;
    }
};
Rocket* Rocket::ms_rocket = NULL;

class Car {
public:
//    const int m_price = 0;
    const int mc_price;
    int m_age;
    int &m_age2 = m_age;
    Car():mc_price(0){
        
    }
    void run(){
       cout << "run()" << endl;
    }
    void run() const;
    static void text(){
        
    }
};

void Car::run() const {
    cout << "run() const " << endl;
    text();
}

class Car2 {
    int m_price;
    int m_length;
public:
    Car2(int price= 0,int length = 0):m_price(price),m_length(length){
        cout << "Car(int price = 0,int length = 0)" << endl;
    }
    // copy 构造函数
    Car2(const Car2& car):m_price(car.m_price),m_length(car.m_length){
        cout << "Car2(const Car2& car)" << endl;
//        m_price = car.m_price;
//        m_length = car.m_length;
    }
    
    void display(){
        cout << "price" << m_price << ",length =" << m_length << endl;
    }
};


void testRocket(void)
{
    Rocket* p1 = Rocket::shareRocket();
    Rocket* p2 = Rocket::shareRocket();
    Rocket* p3 = Rocket::shareRocket();
    Rocket* p4 = Rocket::shareRocket();
//    p->run();
    cout << p1 << endl;
    cout << p2 << endl;
    cout << p3 << endl;
    cout << p4 << endl;
    
//    Rocket::deleteRocket();
    p1->deleteRocket();
    
}

void test01(void)
{
    Car car;
    car.run();
    const Car car2;
    car2.run();
    
    Car2 car3(100,5);
//   回调copy构造函数初始化
    Car2 car4(car3);
    car4.display();
}

int main(int argc, const char * argv[])
{
    test01();
    
    return 0;
}
