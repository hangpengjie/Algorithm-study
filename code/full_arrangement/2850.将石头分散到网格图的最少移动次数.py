from typing import *
from math import *
from itertools import permutations

# 题目链接
# https://leetcode.cn/problems/minimum-moves-to-spread-stones-over-grid/
# 注意观察，发现每个要移除总数 = 移入总数
# 这时候就可以枚举移除的全排列，寻找曼哈顿距离总和最小值 

class Solution:
    def minimumMoves(self, grid: List[List[int]]) -> int:
        from_ = []
        to = []
        for i in range(3):
            for j in range(3):
                if grid[i][j] > 1:
                    from_.extend([(i,j)] * (grid[i][j] - 1))
                if grid[i][j] == 0:
                    to.append((i,j))
        ans = inf
        for from2 in permutations(from_):
            tot = 0
            for (x1,y1),(x2,y2) in zip(from2,to):
                tot += abs(x1 - x2) + abs(y1 - y2)
            ans = min(ans,tot)
        return ans