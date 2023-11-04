from typing import *
from math import *
from functools import cache
from queue import *
from heapq import *
from itertools import *
from bisect import bisect_left

'''
    题目: 1192. 查找集群内的关键连接
    链接: https://leetcode.cn/problems/critical-connections-in-a-network/description/
    思路: Tarjan 寻找桥模板题
'''

# start-----------------------------------------------------
class Tarjan:
    '''
        n: 顶点数量
        edges: 存储的边
        root: 以root为根节点
    '''
    def __init__(self, n: int, edges: List[List[int]],root:int) -> None:
        self.low = [0] * (n + 1)    # 最短到达该顶点时间
        self.dfn = [0] * (n + 1)    # dfs序到达该顶点时间
        self.parent = [-1] * (n + 1)# 顶点的父节点
        self.vis = [False] * (n + 1)# 该顶点是否被访问
        self.isCutVer = [False] * (n + 1) # 是否是割点
        self.isBridge = [False] * (n + 1) # (parent[v], v) 是否是桥
        self.clock = 1 # 时间戳

        self.V = None    # 存储割点
        self.B = None    # 存储桥

        # 边存储方式 (u, v)
        self.edges = edges
        self.n = n
        self.g = [[] for _ in range(n + 1)]
        for u,v in edges:
            self.g[u].append(v)
            self.g[v].append(u)
        
        self.tarjan(root, -1)
    # tarjan算法
    def tarjan(self,u:int, father:int):
        self.parent[u] = father
        self.vis[u] = True
        self.low[u] = self.dfn[u] = self.clock
        self.clock += 1
        child = 0
        for v in self.g[u]:
            if not self.vis[v]:
                child += 1
                self.tarjan(v, u)
                self.low[u] = min(self.low[u], self.low[v])
                # 如果存在子节点 low[v] >= dfn[u] 则说明子节点v必经过u, u是个割点
                if father != u and self.low[v] >= self.dfn[u] and not self.isCutVer[u]:
                    self.isCutVer[u] = True
                # 如果子节点 low[v] > dfn[u] 则说明子节点v必经过u, (u, v) 是个桥
                if self.low[v] > self.dfn[u]:
                    self.isBridge[v] = True
            elif v != father:
                self.low[u] = min(self.low[u], self.low[v])
        # 超过一个孩子则该点是割点
        if father == u and child >= 2 and not self.isCutVer[u]:
            self.isCutVer[u] = True
    # return 割点集合
    def getCutVer(self) -> Set:
        self.V = set()
        for i, x in enumerate(self.isCutVer):
            if x:
                self.V.add(i)
        return self.V
    # return 桥集合
    def getBridge(self) -> Set:
        self.B = set()
        for i in range(self.n + 1):
            if self.isBridge[i]:
                self.B.add((i, self.parent[i]))
        return self.B
    
    
class Solution:
    def criticalConnections(self, n: int, connections: List[List[int]]) -> List[List[int]]:
        tar = Tarjan(n, connections, 0)
        s  = tar.getBridge()
        ans = []
        for u,v in connections:
            if (u,v) in s or (v,u) in s:
                ans.append([u,v])
        return ans


# end-------------------------------------------------------
