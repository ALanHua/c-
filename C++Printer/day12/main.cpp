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
    string word1 {"A jackhammer"};
    string word2 {"jack"};
    
    if (word1 < word2) {
        std::cout << word1 << " comes before " << word2 << '.' << std::endl;
    }else {
        std::cout << word2 << " comes before " << word1 << '.' << std::endl;
    }
    // 取下标2--word2.length()范围内word1的字串和word2比较
    int resultCopare = {word1.compare(2,word2.length(),word2)};
    cout << resultCopare << endl;
    // 寻找word3在text中的所有起始下b标
    string text {"Peter Piper picked a peck of pickled pepper."};
    string word3 {"pick"};
    for (size_t i{}; i < text.length() - word3.length() + 1; ++i) {
        if (text.compare(i, word3.length(), word3) == 0) {
           cout << word3 << " starting at index " << i << endl;
        }
    }
    // 拿一个字符串的子串和y另一个字符串的子串比较
    string phrase2 {"Got to pick a pocket or two."};
    for (size_t i{}; i < text.length() - 3; ++i) {
        if (text.compare(i, 4,phrase2,7,4) == 0) {
            cout << i << " "<< phrase2.substr(7,4) << endl;
        }
    }
    // 查找子串
    string sentence2 {"Manners maketh man"};
    string word5 {"man"};
    cout << "-----------------" << endl;
    cout << sentence2.find(word5) << endl;
    cout << sentence2.find("an") << endl;
    // std::string::npos 等于 2的64次方 - 1
    cout << sentence2.find("x") << ","<< string::npos << endl;
    if (sentence2.find("x") == string::npos) {
       std::cout << "Character not found" << std::endl;
    }
    // 查找子串从指定下标位置开始查找
    cout << sentence2.find("an",1) << endl;
    cout << sentence2.find("an",3) << endl;
    // 从小标为1开始查找"akat"的前2个字符组成的子串
    cout << sentence2.find("akat",1,2) << endl;
    cout << sentence2.find("akat",1,3) << endl;
    // 搜索任意字符中的任意一个
    string text2 {"Smith, where Jones had had \"had had\", had had \"had\"."
        " \"Had had\" had had the examiners' approval."};
    string separators {" ,.\""};
    cout << text2.find_first_of(separators) << endl;
    cout << text2.find_first_of("AaEeIiOoUu") << endl;
    cout << text2.find_last_of("AaEeIiOoUu") << endl;
    cout << text2.find_first_not_of("AaEeIiOoUu") << endl;
    cout << text2.find_last_not_of("AaEeIiOoUu") << endl;
    // 反向搜索
    cout << sentence2.rfind(word5) << endl;
    // 字符串的修改
    string phrase3 {"We can insert a string."};
    string words {"a string into "};
    phrase3.insert(14,words);
    cout << phrase3 << endl;
    // 插入字符串的子串words 下标为8的后面5个字符
    phrase3.insert(0,words,9,5);
    cout << phrase3 << endl;
    // 插入字符串的前5个字符
    phrase3.insert(0,"into somthing",5);
    cout << phrase3 << endl;
    // 插入7个“*”字符
    phrase3.insert(0,7,'*');
    cout << phrase3 << endl;
    
    
    return 0;
}
