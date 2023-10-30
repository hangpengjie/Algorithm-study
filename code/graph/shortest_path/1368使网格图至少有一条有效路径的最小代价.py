from typing import *
from math import *
from functools import cache
from queue import *
from heapq import *
from bisect import bisect_left
# start-----------------------------------------------------
'''
    题目: 1368. 使网格图至少有一条有效路径的最小代价
    链接: https://leetcode.cn/problems/minimum-cost-to-make-at-least-one-valid-path-in-a-grid/description/
    思路: 事实上可以把m * n个坐标想象成节点 grid[i][j]表示方向, 每个点都有四个方向
          grid[i][j]指向的边权值为 0, 其余三条边权值为 1, 也就是说最终要求的便是 (0,0)到(m-1,n-1)的最短路径
          可以使用 Dijkstra 算法求
'''
class Solution:
    def minCost(self, grid: List[List[int]]) -> int:
        m,n = len(grid), len(grid[0])
        dx = [0,0,0,1,-1]
        dy = [0,1,-1,0,0]
        dist = [inf] * (m * n)      # (0,0) 到其他点的最短路径
        seen = [False] * (m * n)
        dist[0] = 0
        pq = PriorityQueue()
        pq.put((0, 0))

        while not pq.empty():
            cur_dis,cur_pos = pq.get()
            if seen[cur_pos]:
                continue
            seen[cur_pos] = True
            for i in range(1, 5):
                x, y = cur_pos // n, cur_pos % n
                nx, ny = x + dx[i], y + dy[i]
                new_dis, new_pos = cur_dis + (i != grid[x][y]), nx * n + ny
                if nx >= 0 and nx < m and ny >= 0 and ny < n and new_dis < dist[new_pos]:
                    dist[new_pos] = new_dis
                    pq.put((new_dis, new_pos))                    
        return dist[m * n - 1]
s = Solution()
s.minCost([[4]])
# end-------------------------------------------------------
