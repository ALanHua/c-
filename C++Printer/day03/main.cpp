//
//  main.cpp
//  day03
//
//  Created by yhp on 2018/10/22.
//  Copyright © 2018 none. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

class CSD1212Stu{
    string name;
    //   静态成员变量，属于这个类的对象公用一份，在类外面初始化时需要加::
    static string teacher;
public:
    CSD1212Stu(const string& n){
        this->name = n;
    }
    void listen(){
        cout << name << "在上课," << teacher << endl;
    }
//    静态成员函数是类对象公共的行为，不一样与对象，yinc函数中不存在this
//    只能访问静态成员，访问非静态成员必须指明对象
    static void changeTeacher(const string &t){
        teacher = t;
    }
};

// 单例模式
/**
 c++ 11之后的static 是线程安全的
 b任意两个单例不能相互引用对方的实例
 */
class ChairMan {
private:
    const string name;
//   初始化列表
    ChairMan(string name):name(name){}
//   copy 构造静止
    ChairMan(ChairMan const& ){}
//   禁止=运算
    ChairMan& operator = (ChairMan const&);
//   禁止析构
    ~ChairMan(){}
public:
//   这样有问题
    static ChairMan& getInstance(){
        static ChairMan cm("xi da da");
        return cm;
    }
    void show(){
        cout << "are you ok! i am " << name << endl;
    }
};

class File {
    string path_;
public:
    File(const string& path = "无名"):path_(path){
        cout << "创建文件" << path_ << endl;
    }
};

string CSD1212Stu::teacher = "andy";

int main(int argc, const char * argv[]) {
    
    CSD1212Stu a("安然");
    CSD1212Stu b("sundy");
    a.listen();
    b.listen();
    CSD1212Stu::changeTeacher("权哥");
    a.listen();
    b.listen();
    
    ChairMan& c1 = ChairMan::getInstance();
    c1.show();
    ChairMan& c2 = ChairMan::getInstance();
    c2.show();
    cout << &c1 << "," << &c2 << endl;
    
    File* p1 = new File;
    File* p2 = new File("/etc/passwd");
    File* p3 = new File[3];
    
    delete[] p3;p3 = NULL;
    delete p2;p2 = NULL;
    delete p1;p1 = NULL;

    return 0;
}
