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
 构造函数，可以重载，一般是公开的，如果一个类没有构造函数
 编译器j会自动产生一个，不干事的空函数，只要有构造函数，编译器就不再
 为这个类产生无惨的k构造函数(默认构造函数)
 */
using namespace std;

int thisyear;
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

struct cDate {// 默认不公开 private
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

class Person{
private:
    string   name;
    int      year;
    bool     gender;
    Person*  lover;
public:
    Person(){
        
    }
    Person(const string& name,bool gender){
        this->name = name;
        year = thisyear;
        this->gender = gender;
        lover = NULL;
    }
    
    void birth(string n,int y);
    void show();
    void love(Person& x){
        // 隐含参数 Person* const this;
        lover = &x;
        x.lover = this;
    }
    void breakUp(){
        lover->lover = NULL;
        lover = NULL;
    }
};

void Person::birth(string n, int y)
{
    name = n;
    year = y;
}

void Person::show()
{
    cout << name << "," << year <<endl;
    if (lover) {
        cout << lover->name << endl;
    }else{
        cout << "NULL" << endl;
    }
}

class Cat{
    
public:
    /**无惨构造器*/
    Cat(){
        cout << "call Cat()" << endl;
    }
    Cat(string n){
        cout << n << " coming in" << endl;
    }
};

int main(int argc, const char * argv[]) {
    
    sDate s;
    cDate c;
    
    s.set(2012, 12, 21);
    c.set(2013, 1, 17);
    s.print();
    c.print();
    
    Person a,b;
    a.birth("andy", 1991);
    b.birth("toly", 2012);
    a.show();
    b.show();
    
    Cat cat; //无惨k构造器
    Cat cat1("cat");// 有参构造器
//    Cat cat2();// 声明一个函数c3,返回值类型是Cat,参数表空
    thisyear = 2018;
    Person p("andy",true);
    Person p1("lili",false);
    p.show();
    p.love(p1);
    p.show();
    p.breakUp();
    
    return 0;
}
