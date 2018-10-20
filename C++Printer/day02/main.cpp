//
//  main.cpp
//  day02
//
//  Created by yhp on 2018/10/20.
//  Copyright © 2018 none. All rights reserved.
//

#include <iostream>

/*
 #include<cstring>
 ...
 namespace std{
     #include <string.h>
 }
 c++
 抽象:
 封装:
    1,数据 -> struct
    2,类   -> class
 结构,默认就是简单打包，对外透明的，可以任意访问成员
 类，默认是保密封装，对外不透明，不允许变量直接访问它的成员
 公开的(public),
 */
using namespace std;
struct sDate {
    int year;
    int month;
    int day;
    void set (int y,int m,int d){
        year = y;
        month = m;
        day = d;
    }
    
    void print(){
        cout << year << '-' << month << '-' << day << endl;
    }
};

struct cDate {
    int year;
    int month;
    int day;
public:
    void set (int y,int m,int d){
        year = y;
        month = m;
        day = d;
    }
    
    void print(){
        cout << year << '-' << month << '-' << day << endl;
    }
};

int main(int argc, const char * argv[]) {
    
    sDate s;
    cDate c;
    
    s.set(2012, 12, 21);
    c.set(2013, 1, 17);
    s.print();
    c.print();
    
    return 0;
}
