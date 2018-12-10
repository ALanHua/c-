//
//  main.cpp
//  day12
//
//  Created by yhp on 2018/12/10.
//  Copyright © 2018 none. All rights reserved.
//

#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    // 空字符串
    string empty;
    // 定义一个字符串
    string proverb {"Many a mickle makes a muckle."};
    const char* proverb_c_str = proverb.c_str();
    cout << proverb_c_str << endl;
    // c++17 更新 之前是非const
    const char* proverb_data = proverb.data();
    cout << proverb_data << endl;
    // 用字符串的前n个字符初始化一个字符串
    string part_literal { "Least said soonest mended.", 5 };
    cout << part_literal << endl;
    // 用n个字符填充初始化一个字符串
    string sleeping(6,'z');
    cout << sleeping << endl;
    // 用一个字符串初始化另外一个
    string sentence {proverb};
    cout << sentence << endl;
    // 初始化一个字符串带范围0到13
    string phrase {proverb, 0, 13};
    cout << phrase << endl;
    string phrase1 {proverb, 5, 15};
    cout << phrase1 << endl;
    /*
     字符串运算
     **/
    string adjective {"hornswoggling"};
    string word {"rubbish"};
    word = adjective;
    adjective = "twotiming";
    cout << adjective << " " << word << endl;
    // 字符串连接
    string description { adjective  + " " + word + " whippersnapper"};
    cout << description << endl;
    sentence.append(adjective).append(" ").append(adjective);
    cout << sentence << endl;
    string compliment("~~~ What a beautiful name... ~~~");
    // 添加一个字符串的一部分
    sentence.append(compliment,3,22);
    cout << sentence << endl;
    // 字符和数字连接
    string result_string{ "The result equals: "};
    double result = 3.1415;
    cout << ( result_string + to_string(result)) << endl;
    /* 访问字符串的字符数据*/
    for (size_t i {}; i < sentence.length(); ++i) {
        sentence[i] = toupper(sentence[i]);
    }
    for (auto ch : sentence) {
        cout << ch;
    }
    cout << endl;
    for (auto& ch: sentence) {
        ch = tolower(ch);
    }
    for (auto ch : sentence) {
        cout << ch;
    }
    cout << endl;
    // 字符串比较
    
    
    
    return 0;
}
