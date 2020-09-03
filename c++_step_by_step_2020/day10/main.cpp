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
 */
// typename == class

class Point {
    int m_x;
    int m_y;
public:
    Point(int x,int y):m_x(x),m_y(y){
        
    }
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
//    Array<Point> array2;
//    array2.add(Point(1,2));
//    array2.add(Point(3,4));
////    cout << array2.get(0) << endl;
//    cout << array2.size() << endl;
    
}

int main(int argc, const char * argv[]) {
    testTemplate();
    return 0;
}
