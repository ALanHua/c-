//
//  main.cpp
//  day09
//
//  Created by yhp on 2018/11/9.
//  Copyright © 2018 none. All rights reserved.
//

#include <iostream>

// 测试简单，正式z程序不建议在这里使用全局
using namespace std;
/**
 函数模板一般可以自动实例化,类模板要认为实例化
 重载(函数模板)，(全/偏)特化(类模板)，非类型形参,
 形参默认值，从右到左
///////////////////////////////////////////
标准模板库STL
 2,介绍STL
    HP公司,高效，少错误检查
    容器container,迭代器，分配器allocator,适配器adapter,算法,防函数functor
    劈开直接的内存和指针操作，用迭代器来表示位置，迭代器是对指针的封装
    支持最基本的操作:*,->,==,!=,++.有的支持--称为双向迭代器,个别迭代器
    还支持+=一个整数称为随机迭代器。
    区间：两个位置之间的数据。含头不含尾。
 3,标准容器
 序列式容器
    vector   向量
    deque    双端队列
    list     链表
 关联时容器
    set      数据集
    multiset 多重数据集
    map      映射
    multimap 多重映射
 4,容器适配类:对容器的再包装,进行了访问限制
    stack    栈
    queue    队列
    priority_queue 优先队列
 5,通用算法:约70种
    
 */

// 模板实现递归
template <typename T,int N>
class A {
public:
    void show()const {
        cout << "normal" << endl;
    }
    static const int v_ = A<T,N-1>::v_ + N;
};

template <typename T>
class A<T,0> {// 对非类型形参的特化
public:
    void show()const{
        cout << "generic0" << endl;
    }
    static const int v_ = 0;
};

template <int N>
class A<double,N> {
public:
    void show()const{// 对类型新参T的特化
        cout << "double" << N << endl;
    }
};

template <typename T,int N>
class A<T*,N> {
public:
    void show()const{// 对类型新参T的特化
        cout << "pointer" << N << endl;
    }
};

template <>
class A<long,8> {
public:
    void show()const{// 对类型新参T的特化
        cout << "long 8" << endl;
    }
};



int main(int argc, const char * argv[]) {
    
    cout << A<int,10>::v_<< endl;
    
    A<int,10>().show();
    A<double,3>().show();
    A<char,0>().show();
    A<short*,5>().show();
    A<long,8>().show();
    
    return 0;
}
