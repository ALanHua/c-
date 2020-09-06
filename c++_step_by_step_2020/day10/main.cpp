//
//  main.cpp
//  day10
//
//  Created by yhp on 2020/9/2.
//  Copyright © 2020 none. All rights reserved.
//

#include <iostream>
#include "add.hpp"
#include "array.hpp"

using namespace std;
/**
-----------------------------
模板template
1,泛型:是一种将类型参数化以达到代码复用的技术,c++中使用模板来实现泛型
2,typename和class是等价的
3,模板没有被使用时，是不会被实例化出来的
4,模板的声明和实现如果分离到.h和.cpp中,会导致连接错误
5,一般将函数模板的声明和实现统一放到一个.hpp文件中
-----------------------------
类型转换 xx_casr<type>(expression)
1,static_cast:一般用在去除const属性,将const转换成非const
2,dynamic_cast:一般用于多态类型的转换，有运行时安全检测
3,reinterpret_cast:属于比较底层的强制转换,没有任何类型检查和格式转换,仅仅是简单的二进制拷贝
4,const_cast:常用于基本数据类型的转换,非const转换成const
-----------------------------
auto
1,可以从初始化表达式中推断出变量的类型,大大简化编程工作
2,属于编译器特性,不影响最终机器码的质量,不影响运行效率
-----------------------------
decltye
1,可以获取变量的类型
-----------------------------
nullptr 空指针
1,可以解决NULL的二义性问题
-----------------------------
 */
// typename == class

class Point {
    friend ostream& operator<<(ostream& cout,const Point &point);
    int m_x;
    int m_y;
public:
    Point(int x = 0,int y = 0):m_x(x),m_y(y){
        
    }
};

ostream& operator<<(ostream& cout,const Point &point){
    return cout << "(" << point.m_x << "," << point.m_y << ")";
}

class Person {
public:
    virtual void run(){}
};

class Student: public Person {
    
public:
    
};

void func(int v){
    cout << "func(int v) -" << v << endl;
}

void func(int* v){
    cout << "func(int* v) -" << v << endl;
}

void testTemplate(void)
{
    cout << add<int>(10,20) << endl;
    cout << add<double>(3.0,4.0) << endl;
    
    Array<int> array(3);
    array.add(10);
    array.add(20);
    array.add(23);
    array.add(24);
    cout << array.get(0) << endl;
    cout << array.size() << endl;
    cout << array[3] << endl;
    
    cout << array << endl;
    Array<Point> array2;
    array2.add(Point(1,2));
    array2.add(Point(3,4));
//    cout << array2.get(0) << endl;
    cout << array2 << endl;
}

void testCast(void)
{
    // const_cast
    const Person* p = new Person();
    Person* p1 = const_cast<Person*>(p);
    cout << p1 << endl;
    Person* p2 = new Student();
    
    Student* stu1 = dynamic_cast<Student*>(p1);// 不安全
    Student* stu = dynamic_cast<Student*>(p2);
    cout << stu << "," << stu1 << endl;
    const Person* p3 = static_cast<Person*>(p1);
    cout << p3 << endl;
    delete p;
    delete p2;
    int a = 10;
    double d = static_cast<double>(a);
    cout << d  << endl;
    cout << "-------" << endl;
    cout << sizeof(int) << endl;
    cout << sizeof(double) << endl;
    double f = reinterpret_cast<double&>(a);
    cout << f << endl;
    
}

void test02()
{
    auto a =10;
    int* p = nullptr;
    func(p);
    func(a);
    int array[] = {11,22,33,44,55};
    // c++11 快速遍历
    for (int item : array) {
        cout << item << endl;
    }
    // 数组简单初始化
    int array2[]{11,22,33,44,55};
    for (int item : array2) {
        cout << item << endl;
    }

}

int main(int argc, const char * argv[]) {
    test02();
    return 0;
}
