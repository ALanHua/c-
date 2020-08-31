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
    
}

int main(int argc, const char * argv[])
{
    testPoint();
    return 0;
}
