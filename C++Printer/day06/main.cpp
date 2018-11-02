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
 
 使用多态d时必须通过父类指针或者引用来访问子类对象
 而不能重建一个父类对象
 
 通过父类指针动态是否子类对象时，默认调用父类的析构
 如果希望也能使用多态调用对象自己的析构，应该在父类中
 把析构函数也声明为虚函数。
 构造函数不能是虚函数更不能是存续函数
 析构函数不能是纯虚函数
 
 string 类 c++ 风格的字符串类
 构造:string(const string& s);
     string(int n,char c);
 运算符:<<,>>,=,+=,+,[]
 */
class Graph {// 抽象类
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

class Coder {
public:
    virtual void code(const char* input,char* output) = 0;
    virtual void decode(const char* input,char* output) = 0;
};

class rm:public Coder {
public:
    void code(const char* input,char* output){
        cout << "用rm格式编码压缩" << endl;
    }
    
    virtual void decode(const char* input,char* output){
        cout << "用rm格式解压缩" << endl;
    }
};

class divx:public Coder {
public:
    void code(const char* input,char* output){
        cout << "用div格式编码压缩" << endl;
    }
    
    virtual void decode(const char* input,char* output){
        cout << "用dir格式解压缩" << endl;
    }
};

class File {
public:
    void setcoder(Coder& c){
        pc_ = &c;
    }
    void zip(){
        const char* soure = "";
        char* result = NULL;
        pc_->code(soure, result);
        cout << "保存到文件中" << endl;
    }
    void unzip(){
        const char* soure = "";
        char* result = NULL;
        pc_->decode(soure, result);
        cout << "播放到大片" << endl;
    }
private:
    Coder* pc_;
};


class A {
public:
    A(){
        cout << "A()" << endl;
    };
    virtual ~A(){
        cout << "~A()" << endl;
    }
    virtual void dosomething(){
        
    }
};

class B :public A{
public:
    B(){
        cout << "B()" << endl;
    };
    ~B(){
        cout << "~B()" << endl;
    }
    virtual void dosomething(){
    }
};

// 纯虚函数:没有必要或者不应该有函数体的虚函数，用 “=0”
int main(int argc, const char * argv[]) {
    Circle c(8,8,10);
    Rect r(0,0,20,5);
    
    Computer::usergraph(c);
    Computer::usergraph(r);
    
    rm r1;
    divx d1;
    File f;
    
    f.setcoder(d1);
    f.zip();
    f.unzip();
    
    f.setcoder(r1);
    f.zip();
    f.unzip();
    
    A* x[2];
//    new和delete 需要一一对应
    x[0] = new B();
    x[1] = new A();
    
    //...
    delete x[0];
    delete x[1];
    
    return 0;
}
