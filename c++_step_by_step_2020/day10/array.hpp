//
//  array.hpp
//  c++_step_by_step_2020
//
//  Created by yhp on 2020/9/3.
//  Copyright © 2020 none. All rights reserved.
//

#ifndef array_hpp
#define array_hpp
#include <iostream>

using namespace std;

template <typename Item>
class Array {
    template <typename Item2>
    friend ostream&operator<<(ostream&,const Array<Item2>&);
    Item* m_data;   // 元素d首地址
    int m_size;    // 元素个数
    int m_capacity;// 容量
public:
    Array(int capacity = 0);
    ~Array();
    void add(Item value);
    Item get(int index);
    int size();
    Item operator[](int index);
};

template <typename Item>
Array<Item>::Array(int capacity){
    m_capacity = (capacity > 0) ? capacity : 10;
    // 申请堆空间
    m_data = new Item[m_capacity];
    m_size = 0;
}

template <typename Item>
Array<Item>::~Array(){
    if (m_data == NULL) return;
    delete [] m_data;
}

template <typename Item>
void Array<Item>::add(Item value){
    if (m_size == m_capacity) {
        // 扩容
        m_capacity = m_size * 2;
        Item* newData = new Item[m_capacity];
        memcpy(newData, m_data, m_size * sizeof(int));
        delete [] m_data;
        m_data = newData;
    }
    m_data[m_size++] = value;
}

template <typename Item>
Item Array<Item>::get(int index){
    if (index < 0 || index >= m_size) {
        // 报错,抛异常
        throw "array index is overflow";
    }
    return m_data[index];
}

template <typename Item>
int Array<Item>::size(){
    return m_size;
}

template <typename Item>
Item Array<Item>::operator[](int index){
    return get(index);
}

template <typename Item2>
ostream& operator<<(ostream& cout,const Array<Item2> &array){
    cout << "[";
    for (int i = 0; i < array.m_size; i++) {
        if (i != 0) {
            cout << ",";
        }
        cout << array.m_data[i];
    }
    
    return cout << "]";
}

#endif /* array_h */
