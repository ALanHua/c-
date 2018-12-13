//
//  main.cpp
//  day13
//
//  Created by yhp on 2018/12/13.
//  Copyright © 2018 none. All rights reserved.
//

#include <iostream>

using namespace std;

/*
 形参通过引用传递数组
 */


/**
 求10个数据的平均值
 @param array 只能传递10个元素的数组
 @return 平均值
 */
double average10(const double(&array)[10])
{
    double sum{};
    for (size_t i {};i < 10;++i) {
        sum += array[i];
    }
    return sum / 10;
}

double average10_(const double(&array)[10])
{
    double sum{};
    for (auto val : array) {
        sum += val;
    }
    return sum / 10;
}
/**
 string_view   C++17 新添加
 */
// 函数形参带默认值
void show_error(string_view message = "Program Error")
{
      std::cout << message << std::endl;
}

int main(int argc, const char * argv[]) {
    
    show_error();
    
    show_error("Nothing works!");
    
    return 0;
}
