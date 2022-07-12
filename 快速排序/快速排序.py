#!/usr/bin/env python      
# -*- coding: utf-8 -*-
# @Author  : ycli
# @Time    : 2022/7/11 17:13
# @File    : 快速排序.py
# @annotation    : 快速排序，使用递归实现和循环实现



def quick_sort_recursion(arr):
    '''
    递归方式的快速排序
    :param arr: 排序前的列表
    :return: 排序后的列表
    '''
    # 如果列表长度小于2则列表肯定有序，直接返回
    if len(arr) < 2:
        return arr

    # 建立排序后的列表
    low_arr = []  # 存储比基准数小的元素
    high_arr = []  # 存储比基准数大的元素
    cur = arr.pop(0)  # 基准数

    # 列表长度大于1，将列表根据基准数分为两部部分
    for i in arr:
        low_arr.append(i) if i < cur else high_arr.append(i)

    # 递归排序
    return quick_sort_recursion(low_arr) + [cur] + quick_sort_recursion(high_arr)


def quick_sort_loop(arr):
    '''
    循环方式的快速排序
    :param arr: 排序前的列表
    :return: 排序后的列表
    '''
    # 如果列表长度小于2则列表肯定有序，直接返回
    if len(arr) < 2:
        return arr

    # 使用双指针协助排序
    low_index = 0
    high_index = len(arr) - 1

    # 使用栈保存需要排序的分段
    index_stack = [(low_index,high_index)]

    while(len(index_stack)):
        # 取出栈顶元素
        low_index,high_index = index_stack.pop()

        # 如果所需排序列表的长度小于2，则已经有序，不需要再排序
        if high_index - low_index < 1:
            continue

        # 设置基准数的索引和尾指针的索引
        cur_index, h = low_index, high_index
        # 设置基准数
        cur = arr[cur_index]

        # 对于分段内的数据进行一次快速排序
        while low_index < high_index:
            # 左指针指向从左到右第一个大于基准数的索引
            while low_index <= len(arr)-1 and arr[low_index] <= cur:
                low_index += 1
            # 右指针指向从右到左第一个小于基准数的索引
            while high_index >=0 and arr[high_index] >= cur:
                high_index -= 1
            # 如果左指针小于右指针则交换两个指针指向的元素
            if low_index < high_index:
                arr[low_index], arr[high_index] = arr[high_index], arr[low_index]

        # high_index比cur_index小时说明所有元素比cur_index大，此时基准数已在正确位置，不需要再调整
        if high_index < cur_index:
            high_index = cur_index

        # 弹出基准数
        arr.pop(cur_index)
        # 将基准数插入hig_index，使得基准数左边的元素全部小于基准数，右边的元素全部大于基准数
        arr.insert(high_index,cur)

        # 将原列表以基准数为中心，分为左右两个部分，并将每部分的左右起始索引压入栈中
        index_stack.append((cur_index,high_index-1))
        index_stack.append((high_index+1,h))

    # 排序结束，返回排序后的数组
    return arr





def test():
    '''
    测试
    :return:
    '''
    # 原有序列表
    arr = [1,2,3,4,5,6,7,8,9,10]
    arr2 = arr[:]
    print('乱序列表：',arr)
    print('排序后的列表：',quick_sort_recursion(arr))
    print('排序后的列表：', quick_sort_loop(arr2))

    # 原逆序列表
    arr = [i for i in range(10,0,-1)]
    arr2 = arr[:]
    print('乱序列表：', arr)
    print('排序后的列表：', quick_sort_recursion(arr))
    print('排序后的列表：', quick_sort_loop(arr2))

    # 含有重复数字列表
    arr = [1,2,6,4,5,6,7,8,9,3]
    arr2 = arr[:]
    print('乱序列表：', arr)
    print('排序后的列表：', quick_sort_recursion(arr))
    print('排序后的列表：', quick_sort_loop(arr2))

    # 全部相同数字列表
    arr = [0 for i in range(10)]
    arr2 = arr[:]
    print('乱序列表：', arr)
    print('排序后的列表：', quick_sort_recursion(arr))
    print('排序后的列表：', quick_sort_loop(arr2))

if __name__ == '__main__':
    test()