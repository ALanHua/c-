//
//  main.cpp
//  day04
//
//  Created by yhp on 2018/10/25.
//  Copyright © 2018 none. All rights reserved.
//

#include <iostream>

using namespace std;

class NA {
private:
    int     n_;
    double  d_;
public:
    NA(){
    }
//    重载了取地址运算符
    NA* operator &(){
        return NULL;
    }
};

class R {
public:
   explicit R(int n,int d=1):n_(n),d_(d){
        if (d < 0) {
            n_ = -n;
            d_ = -d;
        }
        for (int i = d_; i>1; i--) {
            if ((d_ % i == 0) && (n_ % i == 0)) {
                d_ /= i;
                n_ /= i;
                break;
            }
        }
    }
    
public:
    int n_;
    int d_;
};

ostream& operator <<(ostream& o,const R& x){
    o << x.n_ << '/' << x.d_;
    return o;
}

/**
 c++中,运算符被被当成函数，允许程序员自己规定运算符如何工作
 方法就是自己定义响应的运算符函数
 运算符函数的形参和返回z类型尽量用引用，尽量加const
 
 格式:
 
 返回类型 operator 运算符(参数表)
 
 */
int main(int argc, const char * argv[]) {
    
    NA  a,b;
    
    cout << &a << endl;
    cout << &b << endl;
    
    R r1(6,8),r2(8,-12);
    
    cout << r1 << ","<< r2 << endl;
    
    return 0;
}
