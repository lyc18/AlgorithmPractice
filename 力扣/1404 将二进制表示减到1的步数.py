#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Author  : ycli
# @Time    : 2022/8/4 23:34
# @annotation    :
'''
题目表述：
给你一个以二进制形式表示的数字 s 。请你返回按下述规则将其减少到 1 所需要的步骤数：

如果当前数字为偶数，则将其除以 2 。

如果当前数字为奇数，则将其加上 1 。

题目保证你总是可以按上述规则将测试用例变为 1 。



参考示例：
输入：s = "1101"
输出：6
解释："1101" 表示十进制数 13 。
Step 1) 13 是奇数，加 1 得到 14 
Step 2) 14 是偶数，除 2 得到 7
Step 3) 7  是奇数，加 1 得到 8
Step 4) 8  是偶数，除 2 得到 4 
Step 5) 4  是偶数，除 2 得到 2 
Step 6) 2  是偶数，除 2 得到 1 

输入：s = "10"
输出：1
解释："10" 表示十进制数 2 。
Step 1) 2 是偶数，除 2 得到 1

输入：s = "1"
输出：0
'''


class Solution:
    def numSteps(self, s):
        # 记录计算步数
        option_num = 0
        # 将字符串转为列表
        s = [i for i in s]

        # 循环方法
        # while s != ['1']:
        #     option_num += 1 # 步数加1
        # # 如果当前为0，则加1
        #     if s == ['0']:
        #         s = ['1']
        #         continue
        # # 如果字符为偶数则除2
        #     if s[-1] == '0':
        #         s.pop()
        # # 如果字符为奇数，则加1
        #     elif s[-1] == '1':
        #         for i in range(len(s)-1, -1, -1):
        #             if s[i] == '1':
        #                 s[i] = '0'
        #                 # 字符进位
        #                 if i == 0:
        #                     s.insert(0, '1')
        #             elif s[i] == '0':
        #                 s[i] = '1'
        #                 break
        #

        # 递归方法
        def numStep(s, option_num):
            if len(s) == 1:
                return option_num
            if s[-1] == '0':
                return numStep(s[:-1], option_num + 1)
            if s[-1] == '1':
                for i in range(len(s)-1, -1, -1):
                    if s[i] == '1':
                        s[i] = '0'
                    elif s[i] == '0':
                        s[i] = '1'
                        return numStep(s, option_num + 1)
                s.insert(0, '1')
                return numStep(s, option_num + 1)

        # return option_num
        return numStep(s, option_num)


# 其他方法（题解）
# 数学方法
class Solution:
    def numSteps(self, s: str) -> int:
        #特殊情况只是开头有1
        if s[1::].count("0") == len(s)-1: return len(s)-1
        """
        1.一定会进行移位，所以次数为len(s)-1
        2.因为偶数才会直接除，当第一次遇见1时会进行2次操作
        3.在第一个和最后一个1之间的0，会因为进位而进行两次操作，所以统计第一个1和第二个1之间的0的个数 zero
        最后结果 cnt = len(s)-1+2+zero = len(s)+1+zero
        """
        cnt = len(s) + 1
        for i in range(len(s)):
            if "1" not in s[i+1::]: break
        return cnt + s[:i].count("0")

# 转进制处理
class Solution:
    def numSteps(self, s: str) -> int:
        #字符串转为2进制下的十进制
        s = int(s,2)
        cnt = 0
        while s > 1:
            #判断最后一位是否为1，不管结果如何都算一步
            if s&1 == 1:
                s += 1
            elif s&1 == 0:
                s = s>>1
            cnt += 1
        return cnt


if __name__ == '__main__':
    test = Solution()
    print(test.numSteps("1101"))