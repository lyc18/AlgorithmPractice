#!/usr/bin/env python      
# -*- coding: utf-8 -*-
# @Author  : ycli
# @Time    : 2022/7/13 21:35
# @File    : 广度优先遍历.py
# @annotation    : 广度优先遍历
from collections import deque


def person_is_seller(person):
    '''
    判断是否为所要查找到的元素
    :param person:当前元素
    :return:
    '''
    return person == "ll"

def BFS(name,graph):
    '''
    广度优先遍历
    :param name: 图查找的起始节点
    :param graph: 用于查找的图
    :return:
    '''
    # 定义队列与查找标志列表
    search_queue = deque() # 创建队列
    search_queue += graph[name] # 将根节点加入到队列中
    searched = [] # 查找标志列表

    # 广度优先查找
    while search_queue:
        person = search_queue.popleft() # 元素出列
        if not person in searched: # 如果当前元素未被查找
            if person_is_seller(person): # 查找成功
                print(person)
                return True
            else: # 查找失败将此节点的所有子节点入列，并标志此节点已被查找
                search_queue += graph[person]
                searched.append(person)

    return False

def test():
    '''
    测试
    :return:
    '''
    graph = {"a":["b","d","f"],"b":[":sdf","ll"],"d":[],"f":[],"ll":[],":sdf":[]}
    BFS("a",graph)

if __name__ == '__main__':
    test()
