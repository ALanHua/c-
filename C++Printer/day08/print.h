//
//  print.h
//  C++Printer
//
//  Created by yhp on 2018/11/6.
//  Copyright © 2018 none. All rights reserved.
//

#ifndef print_h
#define print_h
#include <cstring>

namespace Andy {
    
template <typename V>
bool lessthan(const V& lh,const V& rh){
    return lh < rh;
}
// 模板特殊化 const char* 对应 V 对c风格字符串特殊化
template <>
bool lessthan(const char* const & lh,const char* const &rh){
    return strcmp(lh,rh) < 0;
}

// 泛型编程 解决上面的痛点
template <typename T>
void sort(T a[],int n){
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (lessthan(a[i],a[j])) {
                std::swap(a[i], a[j]);
            }
        }
    }
}

template <typename T>
void print(T a[],int n) {
    for (int i = 0; i < n; i++) {
        std::cout << a[i] << " ";
    }
    std::cout << std::endl;
}
    
}

#endif /* print_h */
