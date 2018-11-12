//
//  main.cpp
//  day09
//
//  Created by yhp on 2018/11/9.
//  Copyright © 2018 none. All rights reserved.
//

#include <iostream>
#include <deque>
#include <list>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>

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
 标准容器的共性:
    构造：无惨构造，拷贝构造,区间构造(把一个区间内的数据都放到容器中)
    析构：....
    运算符：=,比较(<,<=,>=,==,!=)
    交换： swap,swap(c1,c2),c1.swap(c2)
    插入：insert(pos,elem) 其中pos是一个迭代器
    删除：erase(pos),erase(beg,end)删除指定位置或者指定区间
    清空：clear,
    辅助：size(),empty(),max_size()
    迭代器：封装的指针，作为容器的内部类型。四种：
    iterator,const_iterator,reverse_iterator,const_reverse_iterator
    接口：begin()返回指向第一个元素的迭代器，end()返回指向最后一个的迭代器
    这倆构成的区间正好是容器中的所有元素，rbegin()返回指向反向的第一个元素
    rend()返回反向的最后一个元素
    容器会自己保存一份数据，自定义类型数据保存在容器中应该支持ck拷贝构造
    和赋值运算符
 序列式容器
    vector   向量(动态数组，可以取代原始数组)
    个性：[] 下标 at(i)和[i] 一样但越界是会抛出异常
    capacity()当前容量，reserve(n)事先分配足以存放
    n个元素的空间从而避免频繁重新分配和是否空间
    迭代器在插入或者删除数据之后，应该重新取得迭代器，它是随机迭代器。
    当然也是双向迭代器。
    容量不足，翻一番
    deque    双端队列
    list     链表
    个性：push_front(elem),pop_front(),remove(elem)删除等于elem的所有元素
    remove_if(bool functor(T))条件删除
    unique() 删除所有相邻的重复元素
    sort() 排序(用<比较) sort(bool myless(T,T))
    reverse()把链表逆序，splice(pos,list2,pos)转移数据
    splice(pos,list2,beg,end)a把list2中的全部，一个或者一段元素转移过来
    merge(list2) 把list2里面的数据归并过来(前提两个都是排好序的)
 共性：
    构造：(元素个数，初始值=零初始化）
    调整： resize(新的大小，初始值=零初始化)
    插入：insert(pos，n,elem),insert(pos,beg,end)
    重设：assign(n,elem),assign(beg,end)
        丢弃容器中原有数据，重设n个elem或者重设为区间[beg,end)的数据
        赋值的语义
    头尾：front(),back(),push_back(elem)在末尾追加数据
 
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

template <typename P>
void print(P beg,P end) {
    while (beg != end) {
        cout << *beg++ << " ";
    }
    cout << endl;
}

bool odd(int d)
{
    return d & 1;
}

int main(int argc, const char * argv[]) {
    
    cout << A<int,10>::v_<< endl;
    
    A<int,10>().show();
    A<double,3>().show();
    A<char,0>().show();
    A<short*,5>().show();
    A<long,8>().show();
    
    cout << "-------迭代器------" << endl;
    deque<const char*> dcc;
    deque<const char*>::iterator it,ie;
    dcc.insert(dcc.begin(), "hello");
    dcc.insert(dcc.begin(), "c++");
    dcc.insert(dcc.end(), "welcome");
    dcc.insert(--dcc.end(), "world");
    
    it = dcc.begin();
    ie = dcc.end();
    while (it != ie) {
        cout << *it++ << " ";
    }
    cout << endl;
    cout << "size " << dcc.size() << endl;
    cout << "max_size " << dcc.max_size() << endl;
    
    deque<const char*>::reverse_iterator ri;
    
    for (ri = dcc.rbegin(); ri != dcc.rend(); ri++) {
         cout << *ri << ",";
    }
    cout << endl;
    
    while (!dcc.empty()) {
        cout << *dcc.begin() << endl;
        dcc.erase(dcc.begin());
    }
    cout << "size " << dcc.size() << endl;
    cout << "-------区间------" << endl;
    int a[10] = {8,6,9,7,5,2,7,3,7,7};
    list<int> li(a,a+6);
    list<int>::iterator it2 = li.begin(),ie2 = li.end();
    sort(a, a+10);
    for (int i = 0 ; i < 10;i++) {
        cout << a[i] << " ";
    }
    cout << endl;
    
    while (it2 != ie2) {
        cout << *it2++ << ",";
    }
    cout << endl;
    cout << "-------序列------" << endl;
    const char* we = "smartwater";
    vector<char> vc(we,we+strlen(we));
    print(vc.begin(), vc.end());
    print(vc.rbegin(), vc.rend());
    vector<char> v2 = vc; // 复制vc
    vc.insert(++++++vc.begin(), '0');// 容器共性
    vc.insert(++++++vc.begin(), 2,'2');// 序列共性
    print(vc.begin(), vc.end());
    const char* s = "20";
    print(v2.begin(), v2.end());
    v2.insert(++++++v2.begin(), s,s + strlen(s));
    print(v2.begin(), v2.end());
    vector<char> v3(5,'*');
    print(v3.begin(), v3.end());
    v3.resize(8,'$');// 旧值还在
    print(v3.begin(), v3.end());
    v3.assign(6, '!');// 旧值不在
    print(v3.begin(), v3.end());
    v3.assign(++v2.begin(), --v2.end());
    print(v3.begin(), v3.end());
    v3.push_back('9');
    print(v3.begin(), v3.end());
    cout << "front " << v3.front() << " back " << v3.back() <<endl;
    vector<int> vi(5);// 5个0
    vi.resize(8,1);// 调整为8个元素，新增3个1
    vi[3] = 123;
    vi.at(5) = 456;
    cout << vi[3] << "," << vi.at(5) << endl;
    cout << vi.capacity() << "," << vi.size()<< endl;
    vi.push_back(8);
    cout << vi.capacity() << "," << vi.size()<< endl;
    vi.push_back(9);
    cout << vi.capacity() << "," << vi.size()<< endl;
    
    vi.push_back(100);
    cout << vi.capacity() << "," << vi.size()<< endl;
    cout << "-------双端队列------" << endl;
    deque<string> task;
    task.push_back("起床");
    task.push_back("洗刷");
    task.push_back("吃饭");
    task.push_back("上班");
    //  显示任务列表
    size_t size = task.size();
    for (int i = 0; i < size; i++) {
        cout << task[i] << " ==> ";
    }
    cout << endl;
    
    while (!task.empty()) {
        cout << task.front();
        task.pop_front();
        cout << " 完成" << endl;
    }
    cout << "-------list------" << endl;
    
    list<int> lis(a,a+10);
    print(lis.begin(), lis.end());
    lis.unique();// 只去掉相邻的元素
    print(lis.begin(), lis.end());
    lis.remove(7);
    print(lis.begin(), lis.end());
    lis.sort();
    lis.reverse();
    print(lis.begin(), lis.end());
    lis.remove_if(odd);
    print(lis.begin(), lis.end());
    lis.push_front(13);
    lis.push_back(34);
    lis.insert(++lis.begin(),2,100);
    print(lis.begin(), lis.end());
    
    int b[5] = {3,6,2,9,7};
    list<int> l2(b,b+5);
    lis.splice(----lis.end(),l2,++l2.begin(),--l2.end());
    print(lis.begin(), lis.end());
    print(l2.begin(), l2.end());
    l2.sort();
    lis.sort();
    lis.merge(l2);
    print(lis.begin(), lis.end());
    print(l2.begin(), l2.end());
    
    int a1[5] = {3,8,6,9,2};
    stack<int> si1;
    queue<int> qi1;
    priority_queue<int> pi1;// 默认小于比较
    
    for (int i = 0; i < 5; i++) {
        si1.push(a1[i]);
        qi1.push(a1[i]);
        pi1.push(a1[i]);
    }
    
    while (!si1.empty()) {
        cout << si1.top() << '\t';si1.pop();
        cout << qi1.front() << '\t';qi1.pop();
        cout << pi1.top() << '\n';pi1.pop();
    }
    
    return 0;
}

