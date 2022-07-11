#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Author  : ycli
# @Time    : 2022/7/10 10:12
# @File    : 选择排序.py
# @annotation    : 升序选择排序

import random

def findSmallest(arr):
    '''
    查找列表中最小的元素
    :param arr: 查找列表
    :return: 列表中最小元素在列表中的索引
    '''
    # 定义变量
    smallest_index = 0 # 存储最小元素的索引
    smallest = arr[smallest_index] # 存储最小元素的值

    # 遍历列表，查找最小元素的索引
    for i in range(1,len(arr)):
        # 如果当前元素比最小元素小，则更新最小元素与其索引
        if arr[i] < smallest:
            smallest = arr[i]
            smallest_index = i

    # 返回最小元素的索引
    return smallest_index

def selectionSort(arr):
    '''
    选择排序，升序排序
    :param arr: 需要排序的列表
    :return: 排序后的列表
    '''
    # 定义用于存放排序后列表
    new_array = []

    # 遍历需要排序的列表，每次弹出列表中的最小值，并依次存入道排序后的列表中
    for i in range(len(arr)):
        smallest_index = findSmallest(arr)
        new_array.append(arr.pop(smallest_index))

    # 返回排序后的列表
    return new_array

def test():
    '''
    测试算法的准确性
    :return: None
    '''
    # 原列表有序
    arr = [i for i in range(10)]
    print("排序前：",arr)
    print("排序后：",selectionSort(arr))

    # 原列表倒序
    arr = [i for i in range(10,0,-1)]
    print("排序前：", arr)
    print("排序后：", selectionSort(arr))

    # 原列表乱序
    arr = [i for i in range(10)]
    random.shuffle(arr)
    print("排序前：", arr)
    print("排序后：", selectionSort(arr))

if __name__ == '__main__':
    test()