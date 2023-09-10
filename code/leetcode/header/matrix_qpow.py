from math import *
from queue import PriorityQueue,Queue
from typing import *
from heapq import *
from functools import lru_cache,cache
from string import *
# by hangpengjie

# START CUT
# 矩阵相乘
def matrix_mul(A: List[List[int]],B: List[List[int]], mod = 10 **9 + 7)->List[List[int]]:
    n,m = len(A),len(A[0])
    p = len(B[0])
    ans = [[0] * p for _ in range(n)]
    for i in range(n):
        for j in range(m):
            for k in range(p):
                ans[i][k] += A[i][j] * B[j][k]
                ans[i][k] %= mod
    return ans  
# 矩阵快速幂
def matrix_pow(A: List[List[int]],n:int) ->List[List[int]]:
    length = len(A)
    ans = [[0] * length for _ in range(length)]
    for i in range(length):
        ans[i][i] = 1
    while n:
        if n & 1:
            ans = matrix_mul(ans,A)
        A = matrix_mul(A,A)
        n >>= 1
    return ans
# END CUT

# 例题
# 力扣：https://leetcode.cn/problems/string-transformation/description/