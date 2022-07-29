#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Author  : ycli
# @Time    : 2022/7/29 23:56
# @annotation    :
'''
题目表述：
给定2D空间中四个点的坐标p1,p2,p3和p4，如果这四个点构成一个正方形，则返回 true 。

点的坐标pi 表示为 [xi, yi] 。输入 不是 按任何顺序给出的。

一个 有效的正方形 有四条等边和四个等角(90度角)。


参考示例：
输入: p1 = [0,0], p2 = [1,1], p3 = [1,0], p4 = [0,1]
输出: True

输入：p1 = [0,0], p2 = [1,1], p3 = [1,0], p4 = [0,12]
输出：false

输入：p1 = [1,0], p2 = [-1,0], p3 = [0,1], p4 = [0,-1]
输出：true
'''


class Solution:
    def validSquare(self, p1, p2, p3, p4) -> bool:
        # 计算两点之间的距离的平方
        def calculateDistance(point1, point2):
            return (point1[1] - point2[1]) ** 2 + (point1[0] - point2[0]) ** 2

        # 判断三个点是否能组成一个等腰直角三角形
        def isRightTriangle(point1, point2, point3):
            p12 = calculateDistance(point1, point2)
            p13 = calculateDistance(point1, point3)
            p23 = calculateDistance(point2, point3)
            return p12 == p13 and p12 + p13 == p23

        # 按照对角将四个点分为两组
        group1 = []
        group2 = []

        # 如果p1p2的距离等于p1p3的距离，则p1，p4为一组对角，p2，p3为一组对角
        p12 = calculateDistance(p1, p2)
        p13 = calculateDistance(p1, p3)
        p23 = calculateDistance(p2, p3)
        if p12 == p13:
            group1 = [p1, p4]
            group2 = [p2, p3]
        # 如果p1p2的距离等于p2p3的距离，则p2，p4为一组对角，p1，p3为一组对角
        elif p12 == p23:
            group1 = [p2, p4]
            group2 = [p1, p3]
        # 如果p2p3的距离等于p1p3的距离，则p3，p4为一组对角，p1，p2为一组对角
        elif p23 == p13:
            group1 = [p3, p4]
            group2 = [p1, p2]
        else:
            return False

        # 判断是否有重复点点
        # 从一个对角组中选一个点，与另外两个对角，计算三个点是否满足正方形关系
        return group1[0] != group1[1] and isRightTriangle(group1[0], group2[0], group2[1]) and isRightTriangle(
            group1[1], group2[0], group2[1])

if __name__ == '__main__':
    test = Solution()
    ret = test.validSquare(p1 = [0,0], p2 = [1,1], p3 = [1,0], p4 = [0,1])
    print(ret)