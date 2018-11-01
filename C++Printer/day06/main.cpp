//
//  main.cpp
//  day06
//
//  Created by yhp on 2018/11/1.
//  Copyright © 2018 none. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

/**
 有纯虚函数的类型叫做抽象类(缺少函数体),
 不允许直接用抽象类来创建对象，抽象类总是用来
 作为父类，由子类来实现覆盖那些纯虚函数。从而
 可以创建子类类型的对象，子类对象可以当场父类
 对象来引用，可以用父类指针指向子类对象
 */
class Graph {
public:
    Graph(int x,int y):x_(x),y_(y){}
    virtual double area() = 0; // 存续函数
    virtual string Type() = 0; // 纯虚函数
    void show(){
        cout << Type() << "位置(" << x_ << "," << y_ <<  ")面积"
        << area() << endl;
    }
private:
    int x_;
    int y_;
};

class Rect:public Graph {
public:
    Rect(int x,int y,int w,int h):Graph(x,y)
    ,w_(w),h_(h){
        
    }
    double area(){
        return w_ * h_;
    }
    string Type(){
        return "矩形";
    }
private:
    int w_;
    int h_;
};

class Circle:public Graph {
    
public:
    Circle(int x,int y,int r):Graph(x,y),r_(r){
        
    }
    double area(){
        return 3.14 * r_ * r_;
    }
    string Type(){
        return "圆形";
    }
private:
    int r_;
};

class Computer {
public:
    static void usergraph(Graph& g){
        g.show();
    }
};

// 纯虚函数:没有必要或者不应该有函数体的虚函数，用 “=0”
int main(int argc, const char * argv[]) {
    Circle c(8,8,10);
    Rect r(0,0,20,5);
    
    Computer::usergraph(c);
    Computer::usergraph(r);
    
    
    
    
    return 0;
}
