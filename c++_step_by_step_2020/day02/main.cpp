//
//  main.cpp
//  day02
//
//  Created by yhp on 2020/8/2.
//  Copyright © 2020 none. All rights reserved.
//

#include <iostream>
using namespace std;

/*
引用(Refreance) -- 变量的别名
1，对引用做计算相当于对变量别名做计算
2，定义是就必须初始化,不能改变指向
3, 比指针更安全
*/
void testRef(void)
{
    int age = 10;
    // refAge 相当于是age的别名
    int& refAge = age;
    int& ref1 = refAge;
    int& ref2 = ref1;
    
    refAge = 20;
    refAge += 50;
    ref1 += 10;
    ref2 += 10;
    
    cout << age << endl;
}

void swap2(int& v1,int& v2){
    int tmp = v1;
    v1 = v2;
    v2 = tmp;
}

int main(int argc, const char * argv[]) {
    
    int a = 10;
    int b = 20;
    
    swap2(a,b);
    cout << a << " " << b << endl;
    
    return 0;
}
