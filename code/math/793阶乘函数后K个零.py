
from typing import *
from math import *
from functools import cache
from queue import *
from heapq import *
from itertools import *
from bisect import bisect_left

'''
    题目: 793. 阶乘函数后 K 个零
    链接: https://leetcode.cn/problems/preimage-size-of-factorial-zeroes-function/description/
    思路: 难点在于 num! 中 0的个数, 0的个数取决于累乘10的次数, 10可以分解为质因子2和5
          只需要求 num! 中质因子5的数量, 要求质因子5的数量也就是求[1,num]中因子5的个数之和

          考虑[1,n]中质因子p的数量, 考虑p的倍数 n1 = (n / p) ,这些数中至少贡献了n1 个质因子p
          考虑 n2 = (n / p^2), 这些数至少贡献了 n2 个质因子 p
          质因子p的数量为 sum([n/p, n/p^2, ... ... n / p^k])
'''
# start-----------------------------------------------------
class Solution:
    def preimageSizeFZF(self, k: int) -> int:
        # 求 num! 中 0 的个数
        def f(num):
            res = 0
            while num:
                res += num // 5
                num //= 5
            return res
        l,r = 1, int(1e18)
        while l < r:
            m = (l + r) >> 1
            z = f(m)
            # 可以证明如果z == k 只有 5 个
            if z == k:
                return 5
            if z > k:
                r = m
            else:
                l = m + 1
        # 未找到
        return 0
    
# end-------------------------------------------------------
