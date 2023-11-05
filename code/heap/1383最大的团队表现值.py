from typing import *
from math import *
from functools import cache
from queue import *
from heapq import *
from itertools import *
from bisect import bisect_left
# start-----------------------------------------------------
''' 
    题目: 1383. 最大的团队表现值
    链接: https://leetcode.cn/problems/maximum-performance-of-a-team/description/
    思路: 对于此类问题, 存在两个变量 speed 和 efficiency, 通俗解法就是暴力进行解决
          但是时间复杂度位O(n ^ 2)所以是不可行的
          考虑"控制变量法" 定下一个变量efficiency, 在 >= efficiency 的 speed 中找出最大的k-1个
          这样就能在O(nlog(n))时间内解决问题, TOP-K问题用堆来解决
'''
class Solution:
    def maxPerformance(self, n: int, speed: List[int], efficiency: List[int], k: int) -> int:
        pq = PriorityQueue()
        ans = 0
        sum = 0
        for e,s in sorted(zip(efficiency, speed), key=lambda x : -x[0]):
            sum += s
            ans = max(ans, sum * e)
            pq.put(s)
            # pq 中保存 k - 1 个 speed
            if pq.qsize() == k:
                sum -= pq.get()
        return ans % int(1e9+7)
        
# end-------------------------------------------------------
