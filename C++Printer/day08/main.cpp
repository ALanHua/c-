//
//  main.cpp
//  day08
//
//  Created by yhp on 2018/11/6.
//  Copyright © 2018 none. All rights reserved.
//

#include <iostream>
#include <cstring>
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
 
 特殊化有几种层次
 偏向化:带某种偏向的特殊化，比如偏向指针的，偏向数组...
 全特化:模板头的尖括号是空的，全部模板都确定下来了，类似于普通的
     函数和类,但只有在程序中某处z进行了实例化在最终的可
     执行文件中产生代码。
 部分特化:模板的部分形参确定下来了。
 
 成员（友元)函数模板，跟类模板不要用同样的形参名。
 类模板形参可以有默认值，一批默认值的形参靠右
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

// 模板也可以重载
template <typename T>
void print1(T& d)
{
    cout << d << " " << endl;
}
template <typename T>
void print1(const T* p)
{
    print1(*p);
}

template <typename T,int N>
void print1(T(&a)[N])
{
    for (int i = 0; i < N; i++) {
        print1(a[i]);
    }
}

template <>
void print1(const char* s) //对于C风格的特殊化
{
    cout << s << endl;
}

template <typename K,typename V>
struct Pair {
    K   first;
    V   second;
    void show(){
        cout << "nomal(" <<  first << ","
        << second << ")" << endl;
    }
    
    Pair():first(),second(){}
//    模板狗扎函数
    template <typename F,typename Q>
    Pair(const F& x,const Q& y):first(x),second(y){
    
    }
//  赋值运算
    template <typename F,typename Q>
    Pair& operator =(const Pair<F,Q>& p){
        first  = p.first;
        second = p.second;
        return *this;
    }
    
    friend ostream& operator << (ostream& o,const Pair& p){
        o << "(" << p.first << "," << p.second << ")";
        return o;
    }
};

template <typename K>
struct Pair<K,const char*> {
    K        first;
    string   second;
    void show(){
        cout << "2cstr(" <<  first << ","
        << second << ")" << endl;
    }
};

template <typename V>
struct Pair<const char*,V> {
    string     first;
    V          second;
    void show(){
        cout << "1cstr(" <<  first << ","
        << second << ")" << endl;
    }
};

template <>
struct Pair<const char*,const char*> {
    string     first;
    string     second;
    void show(){
        cout << "cstr cstr(" <<  first << ","
        << second << ")" << endl;
    }
    Pair():first(),second(){}
    //    模板狗扎函数
    template <typename F,typename Q>
    Pair(const F& x,const Q& y):first(x),second(y){
        
    }
    //  赋值运算
    template <typename F,typename Q>
    Pair& operator =(const Pair<F,Q>& p){
        first  = p.first;
        second = p.second;
        return *this;
    }
    
    friend ostream& operator << (ostream& o,const Pair& p){
        o << "(" << p.first << "," << p.second << ")";
        return o;
    }
};
// 函数模板
template <typename K,typename V>
Pair<K,V>makepair(K x,V y)
{
    Pair<K,V> pkv = {x,y};
    return pkv;
}
// 新参默认值
template <typename T = int,int N = 10>
class Array {
//  友元函数模板
    template <typename A,int M>
    friend ostream& operator<< (ostream& o,const Array<A,M>& x);
private:
    T a_[N];
public:
    T& operator[](int index){
        //  越界检查略
        return a_[index];
    }
// 重载
   const T& operator[](int index) const{
        //  越界检查略
        return a_[index];
    }
    
    void fill(T start,const T& step){
        for (int i = 0; i < N; i++,start += step) {
            a_[i] = start ;
        }
    }
    
};

template <typename T,int N>
ostream& operator<< (ostream& o,const Array<T,N>& x)
{
    o << "[";
    for (int i = 0; i < N; i++) {
        o << x[i] << " ";
    }
    o << "]";
    
    return o;
}

template <typename T>
T* find(T a[],int n,T d) {
    for (int i = 0; i < n; i++) {
        if (a[i] == d) {
            return a+i;
        }
    }
    return NULL;
}
template <>
const char** find(const char* a[],int n,const char* d) {
    for (int i = 0; i < n; i++) {
        if (strcmp(a[i], d) == 0) {
            return a+i;
        }
    }
    return NULL;
}

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
    
    int x = 123;
    int a[5] = {1,2,3,4,5};
    int b[3][2] = {11,22,33,44,55,66};
    const char* p = "andy";
    print1(x);
    print1(&x);
//    print1<int,5>(a);
    print1(a);
    print1(b);
    print1(p);
    
    Pair<int,double> pid = {3, 5.5};
    Pair<int,const char*> pic = {10, "hello"};
    Pair<const char*,double> pcd = {"hello",1.1};
    Pair<const char*,const char*> pcc = {"hello","world"};
    pid.show();
    pic.show();
    pcd.show();
    pcc.show();
    
    cout << "--------下面解决上面的痛点-----------" << endl;
    makepair(12345, "$").show();
    makepair(12345, 12.4).show();
    makepair("$", 12.4).show();
    makepair("adny", "rich").show();
    
    cout << "------------------" << endl;
    Pair<int, double> pid1(1,2.3);
    Pair<char, int> pci('a',45);
//    cout.setf(ios::showpoint);
    cout << pid1 << endl;
    pid1 = pci;
    cout << pid1 << endl;
    
    Pair<const char*, const char*> pcc1("aa","bb");
    Pair<string, string> pss;
    pss = pcc1;
    cout << pss << pcc1 << endl;
    
    Array<int, 5> arr;
    arr.fill(11, 2);
    cout << arr << endl;
    
    Array<double> arr2;
    arr2.fill(1.2, 1);
    cout << arr2 << endl;
    
    return 0;
}
