from math import *
from queue import PriorityQueue,Queue
from typing import *
from heapq import *
from functools import lru_cache,cache
from string import *
# by hangpengjie
# START CUT
class Solution:
    ''' 如果一个正整数每一个数位都是 互不相同 的，我们称它是 特殊整数 。
        给你一个 正 整数 n ，请你返回区间 [1, n] 之间特殊整数的数目。
        https://leetcode.cn/problems/count-special-integers/
    ''' 
    def countSpecialNumbers(self, n: int) -> int:
        s = str(n)
        @cache
        # i: 当前遍历到第i位
        # mask: 记录前面已经选过的数
        # is_limit: 是否受到n的约束
        # is_num: 前面是否有数字
        def f(i:int,mask:int,is_limit:bool,is_num:bool) ->int:
            if i == len(s):
                return int(is_num)
            res = 0
            # 可以跳过当前位
            if not is_num:
                res = f(i+1,mask,False,False)
            # 如果前面没有数字可以从0开始，否则不行因为不能有前导0
            low = 0 if is_num else 1
            # 如果前面数字和n的一样那么这一位就至多为s[i] 否则可以为9
            up = int(s[i]) if is_limit else 9
            for d in range(low, up+1):
                if (mask >> d & 1) == 0:
                    res += f(i+1, mask | (1 << d), is_limit and d == up, True)
            return res
        # 初始当然是被限制的
        return f(0,0,True,False)
# END CUT
s = Solution()
s.countSpecialNumbers(135)