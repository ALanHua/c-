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
 mov dst,src 将src赋值给dst，类似 dst = src
 [地址值] 中括号里面的都是地址值
 word ptr 两个字节
 dword ptr 四个字节
 */

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

    
    
    return 0;
}
