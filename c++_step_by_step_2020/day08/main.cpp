//
//  main.cpp
//  day08
//
//  Created by yhp on 2020/8/27.
//  Copyright © 2020 none. All rights reserved.
//

#include <iostream>

using namespace std;

/**
 -------------------------
 对象型参数和返回值
 1,使用对象类型作为函数的参数或者返回值,可能产生一些不必要的中间对象
 
 -------------------------
 */
class Car {
    
public:
    Car(){
        cout << "Car(int) -" << this << endl;
    }
    
    Car(const Car& car){
       cout << " Car(const Car& car) -" << this << endl;
    }
    
    void run(){
        cout << "run()" << endl;
    }
};

void test(Car& car){
    
}

Car test2(){
    Car car;
    return car;
}

void testCar(void){
//   平台不一样,结果不一样
    Car car;
    test(car);
    Car car2;
    car2 = test2();
    Car car3 = test2();
}

int main(int argc, const char * argv[]) {
    

    
    return 0;
}
