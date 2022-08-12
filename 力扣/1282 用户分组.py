#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Author  : ycli
# @Time    : 2022/8/12 10:48
# @annotation    :
'''
题目表述：
有n个人被分成数量未知的组。每个人都被标记为一个从 0 到 n - 1 的唯一ID。

给定一个整数数组 groupSizes ，其中groupSizes[i]是第 i 个人所在的组的大小。例如，如果groupSizes[1] = 3，则第 1 个人必须位于大小为 3 的组中。

返回一个组列表，使每个人 i 都在一个大小为groupSizes[i]的组中。

每个人应该恰好只出现在一个组中，并且每个人必须在一个组中。如果有多个答案，返回其中任何一个。可以保证给定输入至少有一个有效的解。



参考示例：
输入：groupSizes = [3,3,3,3,3,1,3]
输出：[[5],[0,1,2],[3,4,6]]
解释：
第一组是 [5]，大小为 1，groupSizes[5] = 1。
第二组是 [0,1,2]，大小为 3，groupSizes[0] = groupSizes[1] = groupSizes[2] = 3。
第三组是 [3,4,6]，大小为 3，groupSizes[3] = groupSizes[4] = groupSizes[6] = 3。
其他可能的解决方案有 [[2,1,6],[5],[0,4,3]] 和 [[5],[0,6,2],[4,3,1]]。

输入：groupSizes = [2,1,3,3,3,2]
输出：[[1],[0,5],[2,3,4]]


'''

class Solution:
    def groupThePeople(self, groupSizes):
        index_dict = {}
        ret = []
        for i in range(len(groupSizes)):
            if groupSizes[i] in index_dict:
                if index_dict[groupSizes[i]] == []:
                    if groupSizes[i] != 1:
                        index_dict[groupSizes[i]] = [[len(ret),1]]
                    ret.append([i])
                else:
                    ret[index_dict[groupSizes[i]][0][0]].append(i)
                    index_dict[groupSizes[i]][0][1] += 1
                    if index_dict[groupSizes[i]][0][1] == groupSizes[i]:
                        index_dict[groupSizes[i]].pop(0)
            else:
                if groupSizes[i] != 1:
                        index_dict[groupSizes[i]] = [[len(ret),1]]
                ret.append([i])
        return ret

'''
官方实现
'''
class Solution:
    def groupThePeople(self, groupSizes: List[int]) -> List[List[int]]:
        groups = defaultdict(list)
        for i, size in enumerate(groupSizes):
            groups[size].append(i)
        ans = []
        for size, people in groups.items():
            ans.extend(people[i: i + size] for i in range(0, len(people), size))
        return ans

'''
两种方法思想相似,但是官方给出的示例代码更加简洁高效
'''

