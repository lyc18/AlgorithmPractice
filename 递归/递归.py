#!/usr/bin/env python      
# -*- coding: utf-8 -*-
# @Author  : ycli
# @Time    : 2022/7/11 10:57
# @File    : 递归.py
# @annotation    : 递归和尾递归
import time


def fibonacciRecursive(n):
    '''
    普通的递归求Fibonacci函数
    :param n: 第n个Fibonacci数
    :return:第n个Fibonacci数
    '''
    if n < 2:
        return n
    return fibonacciRecursive(n-1) + fibonacciRecursive(n-2)

def fibonacciTailRecursive(n,ret1,ret2):
    '''
    尾递归求Fibonacci函数
    :param n: 第n个Fibonacci数
    :param ret1: 第i个Fibonacci数
    :param ret2: 第i+1个Fibonacci数
    :return: 第n个Fibonacci数
    '''
    if n == 0:
        return ret1
    return fibonacciTailRecursive(n-1,ret2,ret1+ret2)

def test():
    '''
    测试
    :return:
    '''
    start_time = time.time()
    print(fibonacciRecursive(30))
    end_time = time.time()
    print("普通递归使用时间：",end_time - start_time)

    start_time = time.time()
    print(fibonacciTailRecursive(30,0,1))
    end_time = time.time()
    print("尾递归使用时间：", end_time - start_time)

if __name__ == '__main__':
    test()
