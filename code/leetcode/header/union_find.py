from typing import *
from math import *
from functools import lru_cache,cache
from queue import PriorityQueue,Queue
import sys
# by hangpengjie

def I():
    return input()

def II():
    return int(input())
 
def MII():
    return map(int, input().split())
 
def LI():
    return list(input().split())
 
def LII():
    return list(map(int, input().split()))

# 见题 https://www.acwing.com/problem/content/240/

# 并查集模板，根节点保存节点个数，非根节点保存到根节点距离
# 1->2->3    1到3的距离为2
# START CUT
class UF:
    def __init__(self,n:int) -> None:
        self.parent = [i for i in range(n + 1)]
        self.rank = [1] * (n + 1)
    def find(self,x:int) -> (int,int):
        if x == self.parent[x]:
            return (x, 0)
        par,dis = self.find(self.parent[x])
        self.rank[x] += dis
        self.parent[x] = par
        return (self.parent[x],self.rank[x])
    def merge(self,x:int,y:int) -> None:
        px,_ = self.find(x)
        py,_ = self.find(y)
        if px == py:
            return
        self.parent[px] = py
        self.rank[px],self.rank[py] = self.rank[py], self.rank[py] + self.rank[px]
# END CUT   
 
def slove()->None:
    t = II()
    uf = UF(int(3e4+10))
    for _ in range(t):
        a = LI()
        if a[0] == 'M':
            uf.merge(int(a[1]),int(a[2]))
        else:
            px,dx = uf.find(int(a[1]))
            py,dy = uf.find(int(a[2]))
            if px == py:
                print(abs(dx-dy)-1)
            else:
                print(-1)
            


    
def __main__():
    T = 1
    while T:
        T -= 1
        slove()

if __name__ == '__main__':
    __main__()
