#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Author  : ycli
# @Time    : 2022/7/26 22:31
# @File    : 95 不同的二叉搜索树2.py
# @annotation    :
'''
题目表述：
给你一个整数 n ，请你生成并返回所有由 n 个节点组成且节点值从 1 到 n 互不相同的不同 二叉搜索树 。可以按 任意顺序 返回答案。

参考示例：
输入：n = 3
输出：[[1,null,2,null,3],[1,null,3,2],[2,1,3],[3,1,null,null,2],[3,2,null,1]]

输入：n = 1
输出：[[1]]
'''


# 树结构体
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def generateTrees(self, n: int):
        # 生成二叉搜索树，二叉搜索树的值为strat到end
        def generateTrees(start, end):
            # 如果开始值大于结束值，则为空树
            if start > end:
                return [None]

            # 用于保存生成的二叉树
            arrayList = []

            # 逐个将要插入的值作为根节点，并生成左右子树
            for i in range(start, end + 1):
                # 生成左子树，返回的是一个包含所有情况的左子树列表
                l_tree = generateTrees(start, i - 1)
                # 生成右子树，返回的是一个包含所有情况的右子树列表
                r_tree = generateTrees(i + 1, end)

                # 遍历所有的左右子树生成不同的二叉搜索树
                for l in l_tree:
                    for r in r_tree:
                        # 生成一颗完整的二叉搜索树
                        tree = TreeNode(i, l, r)
                        # 将二叉搜索树添加到返回列表中
                        arrayList.append(tree)

            # 若n大于0则返回生成的二叉搜索树，否则返回空树
            return arrayList if n else []

        return generateTrees(1, n)

if __name__ == '__main__':
    test = Solution()
    arrlist = test.generateTrees(3)


