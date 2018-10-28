//
//  main.cpp
//  day05
//
//  Created by yhp on 2018/10/28.
//  Copyright © 2018 none. All rights reserved.
//

#include <iostream>

using namespace std;

struct POINT {
    int x;
    int y;
};

class Pos {
public:
    Pos(int x = 0,int y = 0){
        p_.x = x;
        p_.y = y;
    }
    void move(int cx,int cy){
        p_.x += cx;
        p_.y += cy;
    }
    void moveto(int x,int y){
        p_.x = x;
        p_.y = y;
    }
    
    POINT* operator ->() {
        return &p_;
    }
private:
    POINT p_;
};

class A {
public:
    A(int d=0):data_(d){
        cout << "A(" << data_ <<")" << endl;
    }
    ~A(){
        cout << "~A(" << data_ <<")" << endl;
    }
    void* operator new(size_t bytes){
        cout << "bytes=" << bytes << endl;
       return malloc(bytes);
    }
    //  编译器会藏匿几个字节来存储数组大小的值
    //  MAC OS 为 8个字节
    void* operator new[](size_t bytes){
        cout << "BYTES=" << bytes << endl;
        void* p = malloc(bytes);
        cout << "P=" << p << endl;
        return p;
    }
    void operator delete(void* p){
        assert(p != NULL);
        cout << "free " << p << endl;
        free(p);
    }

    void operator delete[](void* p){
        assert(p != NULL);
        cout << "FREE " << p << endl;
        free(p);
    }
        
private:
    int data_;
};

class R {
public:
    friend ostream& operator << (ostream& o,const R& x){
        o << x.n_ << "/" << x.d_;
        return o;
    }
    
    R(int n=0,int d=1):n_(n),d_(d){
        
    }
//   operator++(a) a.operator++()
    R& operator++(){
        n_ += d_;
        return *this;
    }
//  后++ 指定一个虚假的int类型的形参，用于区分前++还是后++
    R operator++(int){
        R old = *this;
        n_ += d_;
        return old;
    }
    
//  友元实现 --
    friend R&operator--(R& x){
        // 不是成员函数b没有当前对象 无法访问this,是哑元
        x.n_ -= x.d_;
        return x;
    }
private:
    int n_;
    int d_;
};
/**
 const对象只能调用const成员函数
 const对象中的mutable修饰的数据成员是允许修改的
 补充:
     const int* p           p指向 cosnt int
     int const *p           // 同上
     int* const p           // p 本身是const
     const int* const p     // p 本身是const,指向const int
 */
int main(int argc, const char * argv[]) {
    
    Pos a(20,80);
    cout << a->x << ","<< a->y << endl;
    a.move(30, -10);
    cout << a->x << ","<< a->y << endl;
    
    A* p = new A[3];
    cout << "sizeof A=" << sizeof(A) << endl;
    cout << "p=" << p << endl;
    delete[] p;
    p = NULL;
    
    R r(3,4);
    ++ ++r;
    cout << r << endl;
    -- --r;
    cout << r << endl;
    r++;
    cout << r << endl;
    
    return 0;
}
