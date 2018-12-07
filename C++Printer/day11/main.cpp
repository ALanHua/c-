//
//  main.cpp
//  day11
//
//  Created by yhp on 2018/12/7.
//  Copyright © 2018 none. All rights reserved.
//

#include <iostream>
#include <vector>
#include <iomanip>
#include <memory>
#include <cctype>

using namespace std;

/**
 现代c++ 建议不要直接使用new new[] delete delete[]
 而建议使用vector等容器或者智能指针
 */


int main(int argc, const char * argv[]) {
    
    // 1,动态分配w二维数组
    auto carrots {new double[3][4]};
    delete [] carrots;
    
    auto* pdata {new vector<int>{}};
    pdata->push_back(66);
    pdata->push_back(100);
    pdata->push_back(50);
    
    for (int i = 0; i < (*pdata).size(); i++) {
        cout << (*pdata)[i] << " ";
    }
    cout << endl;
    delete pdata;
    
    // 智能指针
    auto pUnique {new double(99.0)};
    cout << *pUnique << endl;
    *pUnique = 8888.0;
    cout << *pUnique << endl;
    const size_t n{10};
    auto pvalues{make_unique<double[]>(n)};
    for (size_t i {}; i < n; ++i) {
        pvalues[i] = i + 1;
    }
    for (size_t i {}; i < n; ++i) {
        cout <<  pvalues[i]  << " ";
    }
    cout << endl;
    cout << pvalues.get() << "," << pvalues << endl;
    pvalues.reset();
    cout << pvalues << endl;
    
    vector<shared_ptr<vector<double>>> records;
    size_t day{1};
    for (size_t j{}; j < 2; ++j) {
        auto day_records{make_shared<vector<double>>()};
        records.push_back(day_records);
        std::cout << "Enter the temperatures for day " << day++ << endl;
        for (int i{}; i < 10; ++i) {
            auto t = (i + 2.1) * (j + 1);
            day_records->push_back(t);
        }
    }
    cout << "-------------" << endl;
    for (auto record : records) {
        for (auto temp : *record) {
            cout << setw(4) << temp << " " ;
        }
        cout << endl;
    }
    
    return 0;
}
