//
//  main.cpp
//  day08
//
//  Created by yhp on 2018/11/6.
//  Copyright © 2018 none. All rights reserved.
//

#include <iostream>
#include "print.h"

using namespace std;

#if 0
void sort(int a[],int n){
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (a[i] < a[j]) {
                swap(a[i], a[j]);
            }
        }
    }
}

void sort(char a[],int n){
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (a[i] < a[j]) {
                swap(a[i], a[j]);
            }
        }
    }
}

void sort(double a[],int n){
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (a[i] < a[j]) {
                swap(a[i], a[j]);
            }
        }
    }
}

void sort(string a[],int n){
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (a[i] < a[j]) {
                swap(a[i], a[j]);
            }
        }
    }
}
// 泛型编程 解决上面的痛点
template <typename T>
void sort(T a[],int n){
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (a[i] < a[j]) {
                swap(a[i], a[j]);
            }
        }
    }
}
#endif

/**
 template <typename T> 模板头 T是模板形参
 编译在编译时会确定模板形参具体是那种类型，这个过程
 称为模板的实例化。实例化之后j才称为真正能工作的代码
 模板有函数模板和类(结构）模板
 template <typename T,...>
 其中<>里面的是模板形参，一般是类型，也可以是非类型形参
 (整形形参,在模板里作为整形常量)
 函数模板在实例化时时由编译器把模板形参用具体的类型数据
 或者数据替换之后产生一个函数,不同的实例化得到的是不同的
 函数，它们之间构成重载关系。函数模板一般能有编译器自动
 实例化，类模板也一样
 
 typename 也可以换成 class含义相同，但不建议使用
 
 */

// 模板栈类
// 这个类不完善，只为测试类模板
template <typename T>
class Stack {
public:
    Stack():cnt_(){//零初始化
    }
    
    void push(const T& d){
        a_[cnt_++] = d;
    }
    T& top(){
        return a_[cnt_ - 1];
    }
    void pop(){
        --cnt_;
    }
    bool empty() const {
        return cnt_ == 0;
    }
    int size() const {
        return cnt_;
    }
    bool full() const {
        return cnt_ == 10;
    }
private:
    T a_[10];
    int cnt_;
};

template <typename T,int N>
class Queue {
public:
    Queue():cnt_(){
    }
    Queue& push(const T& d){
        if (cnt_ >= N) {
            throw "full";
        }
        a_[cnt_++] = d;
        return *this;
    }
    
    T& fornt(){
        return a_[0];
    }
    T& back(){
        return a_[cnt_-1];
    }
    void pop(){
        for (int i = 1; i < cnt_; i++) {
            a_[i-1] = a_[i];
        }
        --cnt_;
    }
    bool empty(){
        return cnt_ == 0;
    }
    bool full(){
        return cnt_ == N;
    }
    int size(){
        return cnt_;
    }
    
private:
    T a_[N];
    int cnt_;
};

int main(int argc, const char * argv[]) {
    int ai[6] = {8,1,6,9,3,5};
    char ac[5] = {'d','x','s','a','m'};
    double ad[5] = {5.5,3.3,9.9,6.6,2.2};
    string as[4] = {"good","morning","dear","friends"};
    
    Andy::sort(ai, 6);  Andy::print(ai,6);
    Andy::sort(ac, 5);  Andy::print(ac,5);
    Andy::sort(ad, 5);  Andy::print(ad,5);
    Andy::sort(as, 4);  Andy::print(as,4);
    
//////////////////////////////////////////////////
    Stack<int> si;   // int 模板的实参
    Stack<const char*> ss; // 类模板必须要人为的r实例化
    
    si.push(1);
    si.push(2);
    si.push(3);
    si.push(4);
    
    ss.push("hello");
    ss.push("for");
    ss.push("andy");
    
    while (!si.empty()) {
        cout << si.top() << " ";
        si.pop();
    }
    cout << endl;
    
    while (!ss.empty()) {
        cout << ss.top() << " ";
        ss.pop();
    }
    cout << endl;
    
    return 0;
}
