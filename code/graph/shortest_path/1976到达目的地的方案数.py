from typing import *
from math import *
from functools import cache
from queue import *
from heapq import *
from itertools import *
from bisect import bisect_left


'''
    题目: 1976. 到达目的地的方案数
    链接: https://leetcode.cn/problems/number-of-ways-to-arrive-at-destination/description/
    思路: Dijkstra 算法求最短路径过程中算出路径数量
'''
# start-----------------------------------------------------
class Solution:
    def countPaths(self, n: int, roads: List[List[int]]) -> int:
        g = [[] for _ in range(n)]
        mod = int(1e9+7)
        for u,v,time in roads:
            g[u].append((v,time))
            g[v].append((u,time))
        dist = [inf] * n    # time
        cnt = [0] * n       # 最短时间为time时对应的路径数量
        dist[0] = 0
        cnt[0] = 1
        # (time, node)
        pq = PriorityQueue()
        pq.put((0,0))
        while not pq.empty():
            last_time, u = pq.get()
            for v,time in g[u]:
                if dist[v] > last_time + time:
                    dist[v] = last_time + time
                    pq.put((dist[v], v))
                    cnt[v] = cnt[u]
                # 时间相同
                elif dist[v] == last_time + time:
                    cnt[v] += cnt[u]
        return cnt[-1] % mod
s = Solution()
s.countPaths(7,[[0,6,7],[0,1,2],[1,2,3],[1,3,3],[6,3,3],[3,5,1],[6,5,1],[2,5,1],[0,4,5],[4,6,2]])
# end-------------------------------------------------------
