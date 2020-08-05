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
4, 引用的本质就是指针，只是编译器弱化这个
5, 不存在引用的引用
6, 不存在数组引用
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

// 侧面/证明其本质
struct student {
    int &age;
};

/*
 一个变量的地址值就是它最小的地址值
 大小端
 小端（高高低低,高字节放高地址）
 大端 (低低高高）
 ----------
 -- 通用寄存器
 64bit
 RAX / RBX / RCX /RDX
 32bit
 EAX / EBX /ECX / EDX
 16bit
 AX / BX / CX / DX
 8bit
 AH  --H high
 AL  --L low
 ---寄存器存储空间
 和指针一样,x64上8个字节
 ---
 R开头的64bit
 E开头的32bit
 -----
 mov dword ptr[ebp-8],3
 -----
 汇编指令
 mov dest,src 将src赋值给dest，类似 dest = src
 [地址值] 中括号里面的都是地址值
 word ptr 两个字节
 dword ptr 四个字节
 qword ptr 八个字节
 call 函数地址  -- 调用函数 E8开头的机器码 代表 call
 lea dest,【地址值】 直接将地址值赋值给dest
    -- load effect address 装载有效的地址值
 ret -- 函数返回
 jmp  内存地址  ---- 跳转到地址值中的代码执行 J开头都是跳转有条件指令
 jne          ---- 不相等跳转
 cmp          ---- 比较
 
 xor op1 ,op2 ---- op1 = op1 ^ op2
 add op1,op2  ---- op1 = op1 + op2
 sub op1,op2  ---- op1 = op1 - op2
 inc op       ---- op = op + 1
 des op       ---- op = op -1

 */

struct Date {
    int year;
    int month;
    int day;
};

int main(int argc, const char * argv[]) {
    
    int a = 10;
    int b = 20;
    swap2(a,b);
    cout << a << " " << b << endl;
    cout << sizeof(student) << endl;
    //  内敛汇编
    __asm {
        mov eax,10
        mov rax,1122334455667788H
    }
    
    Date d = {2020,8,5};
    Date& ref = d;
    cout << ref.year << endl;

    int age = 40;
    int* p = &age;
    int* &refp = p;
    cout << *refp << endl;
    int height = 30;
    refp = &height;
    cout << *refp << endl;
    
    int array[] = {1,2,3};
    int (&refArray)[3] = array;
    refArray[0] = 10;
    cout << array[0] << endl;
    //  指针数组
    int* arr1[3] = {p,p,p};
    //  数组指针
    int(*arr2)[3];
    
    return 0;
}
