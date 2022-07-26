#!/usr/bin/env python      
# -*- coding: utf-8 -*-
# @Author  : ycli
# @Time    : 2022/7/11 9:12
# @File    : 二分查找.py
# @annotation    : 在升序排序了列表里进行二分查找

def binary_search(arr,item):
    '''
    二分查找
    :param arr: 查找列表，列表升序排序
    :param item: 查找项
    :return: 查找成功返回查找项的索引，查找失败返回None
    '''
    # 定义查找的low和high游标，分别指向二分查找是查找的起始位置和结束位置
    low = 0
    high = len(arr) - 1

    # 二分查找
    while low <= high:
        mid = int((low + high) / 2) # 计算中间元素的索引

        if arr[mid] == item: # 对比中间值是否与查找项相同，相同则返回查找项的索引
            return mid
        if arr[mid] > item: # 中间值比item大，则item必然只可能在[low,min)范围内
            high = mid - 1
        else: # 中间值比item小，则item必然只可能在(min,high]范围内
            low = mid + 1

    # 查找失败
    return None

def test():
    '''
    测试二分查找
    :return: None
    '''
    arr = [i for i in range(10)]
    print("查找中间值：", binary_search(arr, 4))
    print("查找末项：", binary_search(arr, 9))
    print("查找首项：", binary_search(arr, 0))
    print("查找普通项：", binary_search(arr, 2))
    print("查找不存在的项：", binary_search(arr, 10))


if __name__ == '__main__':
    test()