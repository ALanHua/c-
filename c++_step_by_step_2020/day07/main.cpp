//
//  main.cpp
//  day07
//
//  Created by yhp on 2020/8/24.
//  Copyright © 2020 none. All rights reserved.
//

#include <iostream>
using namespace std;
/**
------------------------
 单例模式:设计模式的一种,保证某个类只创建一个对象
 1,构造函数和析构函数私有化
 2,定义一个私有static成员变量指向y唯一的那个单例对象
 3,提供一个公共的访问单例对象的接口
------------------------
 */
class Rocket {
private:
    static Rocket* ms_rocket;// 内存使用灵活
    Rocket(){}
    ~Rocket(){}
public:
    static Rocket* shareRocket(){
        // 多线程安全问题
        if (ms_rocket == NULL) {
            ms_rocket = new Rocket();
        }
        return ms_rocket;
    }
    static void deleteRocket(){
        // 多线程安全问题
        if (ms_rocket != NULL) {
            delete ms_rocket;
            ms_rocket = NULL;
        }
    }
    void run(){
        cout << "run()" << endl;
    }
};
Rocket* Rocket::ms_rocket = NULL;

void testRocket(void)
{
    Rocket* p1 = Rocket::shareRocket();
    Rocket* p2 = Rocket::shareRocket();
    Rocket* p3 = Rocket::shareRocket();
    Rocket* p4 = Rocket::shareRocket();
//    p->run();
    cout << p1 << endl;
    cout << p2 << endl;
    cout << p3 << endl;
    cout << p4 << endl;
    
//    Rocket::deleteRocket();
    p1->deleteRocket();
    
}

int main(int argc, const char * argv[])
{
    testRocket();
    
    return 0;
}
