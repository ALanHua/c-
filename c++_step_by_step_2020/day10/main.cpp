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
2,dynamic_cast
3,reinterpret_cast
4,const_cast
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
    
};

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
    delete p;
    
}

int main(int argc, const char * argv[]) {
    testCast();
    return 0;
}
