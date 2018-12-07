//
//  main.cpp
//  day10
//
//  Created by yhp on 2018/12/1.
//  Copyright © 2018 none. All rights reserved.
//

#include <iostream>
#include <vector>
#include <array>

using namespace std;

/**
 注意点
 1，template <typename T = double>
    class sum {};
    sum<> s1;
    <> 不能省略
    如果想省略<>
    typedef 重新定义类型
 
 */

// normal class with template member function
struct mathmatics {
    template <typename scalar_t>
    scalar_t sq(scalar_t x) const{
        return x*x;
    }
};

// class template with template member function
template <typename scalar_t>
struct more_mathmatics{
    template <typename other_t>
    static scalar_t product(scalar_t x,other_t y){
        return x*y;
    }
};
/**
 s0 = s1;    // calls user defined operator=
 s1 = s2;    // calls the compiler generated assignment
 */
template <typename T>
class something {
public:
    template <typename S>
    something(const something<S>& that){
        
    }
    template <typename S>
    something& operator= (const something<S>& that){
        return *this;
    }
};

/**
 Function Types and Function Pointers
 A<f> t1;   // ok
 B<f> t2;   // ok
 */
template <double F(int)>
struct A {
};

template <double (*F)(int)>
struct B{
};

double f(int)
{
    return 3.14;
}
//  function templates that get parameters by reference prevent the decay
/*
 identify_by_val(f);  // function decays to pointer-to-function:
 // template instantiated with T = double (*)(int)
 identify_by_ref(f);  // no decay:
 // template instantiated with T = double (int)
 */
template <typename T>
struct X
{
    T member_;
    X(T value)
    : member_(value)
    {
    }
};

template <typename T>
X<T> identify_by_val(T x) {
     return X<T>(x);
}

template <typename T>
X<T> identify_by_ref(const T& x)
{
    return X<T>(x);
}

typedef double (*FUNC_T)(double);
// However, if they are members of class templates and their context depends on a yet unspecified parameter, they require an extra template keyword before their name
template <typename X>
struct outer
{
    template <typename T>
    static T g(T x)
    {
        return x+1;
    }
};
template <typename X>
struct outer2
{
    template <typename T>
    struct inner {};
};
// 调用模板类中的模板函数需要加上 template 关键字
// Both typename and template are required for inner template classes:
template <typename X>
void do_it() {
//    FUNC_T f1 = outer<X>::g<double>;  // error!
//    FUNC_T f2 = outer<X>::template g<double>;     // correct
//     typename outer2<X>::template inner<double> I;
}

/**
 1.5
 If a class template has members that do not depend on its parameters, it may be convenient to move them into a plain class:
 */

template <typename T>
class MyClass {
    double value_;
    std::string name_;
    std::vector<T> data_;
public:
    std::string getName() const;
};
// 应该变成
class MyBaseClass
{
protected:
    ~MyBaseClass(){}
    double value_;
    std::string name_;
public:
    std::string getName() const;
};

template <typename T>
class MyClass1 : MyBaseClass
{
    std::vector<T> data_;
public:
    using MyBaseClass::getName;
};

// enum class 类型安全
enum class Day {
    Monday = 1, Tuesday, Wednesday, Thursday, Friday, Saturday, Sunday
};

enum class Day2 {
    Monday,                 Mon = Monday,
    Tuesday   = Monday+2,   Tues = Tuesday,
    Wednesday = Tuesday+2,  Wed = Wednesday,
    Thursday  = Wednesday+2,Thurs = Thursday,
    Friday    = Thursday+2, Fri = Friday,
    Saturday  = Friday+2,   Sat = Saturday,
    Sunday    = Saturday+2, Sun = Sunday
};

enum class Punctuation: char {
    Comma       = ',',
    Exclamation = '!',
    Question    ='?'
};
    
// Aliases for Data Types 取别名
using BigOnes = unsigned long long;
// typedef using BigOnes = unsigned long long; 和上面等价

// 全局变量和局部变量同名时如何访问
long count1{9999};
    
int main(int argc, const char * argv[]) {

    double A = mathmatics().sq(3.14);
    double B = more_mathmatics<double>().product(3.14, 5);
    
    cout << A << "," << B  << endl;

    cout << static_cast<int>(Day::Wednesday) << endl;
    cout << static_cast<int>(Day2::Wednesday) << endl;
    cout << static_cast<char>(Punctuation::Comma) << endl;
    
    BigOnes mynum {100};
    cout << mynum << endl;
    
    long count1{10};
    cout << count1 << "," << ::count1 << endl;
    
    char letter {'A'};
    
    if (isalpha(letter)) {
        cout << tolower(letter) << endl;
        printf("%c\n",tolower(letter));
    }
    int values[] {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
    
    cout << "There are " << sizeof(values) / sizeof(values[0]) << endl;
    // c++ 17 之后支持这种操作
    cout << std::size(values) << endl;
    
    // for in
    int total {};
    for (auto x : values){
        total += x;
    }
    
    cout << total << endl;
    
    // 使用容器
    array<double, 100> values1;
    values1.fill(3.14);
    cout << values1[1] << "," << values1[2] << endl;
    //  vector
    // 20 个 99
    vector<long> numbers2(20,90L);
    for (int i = 0; i < numbers2.size(); i++) {
        cout << numbers2[i] << " ";
    }
    cout << endl;
    // 重新初始化数组
    numbers2.assign(5,100L);
    for (int i = 0; i < numbers2.size(); i++) {
        cout << numbers2[i] << " ";
    }
    cout << endl;
    // 初始化含有两个元素的数组
    numbers2.assign({30,40});
    for (int i = 0; i < numbers2.size(); i++) {
        cout << numbers2[i] << " ";
    }
    cout << endl;
    
    return 0;
}
