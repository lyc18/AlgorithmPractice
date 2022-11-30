//
// Created by lyc on 2022/11/30.
//

#ifndef ALGORITHMPRACTICE_IOFUNCTION_H
#define ALGORITHMPRACTICE_IOFUNCTION_H
#include <iostream>

/**
 * 输出数组
 * @param array 需要输出的数组
 * @param array_len 数组长度
 */
template<typename T>
void PrintArray(T array, int array_len)
{
    for(int i = 0; i < array_len; ++i)
    {
        std::cout << array[i] << ' ';
    }
    std::cout << std::endl;
}

#endif //ALGORITHMPRACTICE_IOFUNCTION_H
