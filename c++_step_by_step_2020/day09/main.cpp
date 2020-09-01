//
//  main.cpp
//  day09
//
//  Created by yhp on 2020/8/31.
//  Copyright © 2020 none. All rights reserved.
//

#include <iostream>

using namespace std;

/**
------------------------------
运算符重载
1,可以为运算符增加一些新的功能
 
-----------------------------
*/

class Point {
    friend ostream& operator<<(ostream&,const Point&);
    friend istream& operator >>(istream&,Point&);
private:
    int m_x;
    int m_y;
public:
    Point(int x,int y):m_x(x),m_y(y){
        
    }
    
    Point(const Point& point){
        m_y = point.m_y;
        m_x = point.m_x;
    }
    
    void display(){
        cout << "(" << m_x << "," << m_y << ")" <<endl;
    }
    
    const Point operator+(const Point& point) const {
        return Point(point.m_x + m_x, point.m_y + m_y);
    }
    
    const Point operator-(const Point& point) const{
        return Point(m_x - point.m_x,  m_y - point.m_y);
    }
    
     Point& operator+=(const Point& point){
         m_x += point.m_x;
         m_y += point.m_y;
         return *this; // 返回对象引用的对象
    }
    
    bool operator==(const Point& point) const{
        return (m_x == point.m_x && m_y == point.m_y);
    }
    
    bool operator!=(const Point& point) const{
        return (m_x != point.m_x && m_y != point.m_y);
    }
    
    const Point operator-()const{
        return Point(-m_x,-m_y);
    }
    
    // 前置++
    Point& operator++(){
        m_x++;
        m_y++;
        return *this;
    }
    
    // 后置++
    const Point operator++(int){
        Point old(m_x,m_y);
        m_x++;
        m_y++;
        return old;
    }
    
};

// output stream -> ostream
ostream& operator<<(ostream& cout,const Point& point){
    cout << "(" << point.m_x << "," << point.m_y << ")";
    return cout;
}

istream& operator >> (istream& cin,Point& point){
    cin >> point.m_x;
    cin >> point.m_y;
    return cin;
}

class Person {
    int m_age;
    int m_height;
    void operator=(const Person& person){}
public:
    Person(int age = 0,int height = 0):m_age(age),m_height(height){}
//    Person& operator=(const Person& person){
//        m_age = person.m_age;
//        return *this;
//    }
    void display(){
        cout << m_age << "," << m_height << endl;
    }
};


void testPoint(void)
{
    Point p1(10,20);
    Point p2(20,30);
    Point p3(40,50);
    Point p4 = p1 + p2 - p3;
//    Point p4 = operator+(p1,p2); // 等价p3
    p4.display();
    
    Point p5 = p2 -p1;
    p5.display();
    (p5 += p4) = Point(50,100);
    p5.display();
    cout << (p1 == p2) << endl;
    Point p6 = -p5;
    p6.display();
    
    Point p7(10,20);
    Point p8 = p7++ + Point(30, 40);
    p7.display();
    p8.display();
    cout << "---------" << endl;
    cout << p7 << p8 << endl;
//    cin >> p7 >> p8;
//    cout << p7 << p8 << endl;
    
    Person a1(10,180);
    Person a2(20,175);
//    (a1 = a2) = Person(50,20); // 赋值函数私有化后就无法赋值
    a1.display();
}

int main(int argc, const char * argv[])
{
    testPoint();
    return 0;
}
