from typing import *
from math import *
# 题目链接：

# start-----------------------------------------------------
'''
    本题知识点：和为M的数组中不同的数字最多有sqrt(M)个
    前缀和优化：f[i]表示和为i的子多重集合数目
        cnt[k] = v时
        f[i] = f[i] + f[i-k] (k <= i <= r)
    考虑到cnt[k] 最大值为 v 因此背包内最多有 v 个k
    前面的计算中没有限制 k 的个数，对于[(v+1) * k, r] 
        f[i] = f[i] - f[i - (v+1) * k] 
'''
class Solution:
    def countSubMultisets(self, nums: List[int], l: int, r: int) -> int:
        mod = int(1e9+7)
        f = [0] * (r +  1)
        f[0] = 1
        c = Counter(nums)
        for k,v in c.items():
            if k == 0:
                f = [x * (v + 1) for x in f]
            else:
                for i in range(k, r+1):
                    f[i] = (f[i] + f[i-k]) % mod
                for i in range(r, (v+1)*k-1, -1):
                    f[i] = (f[i] - f[i - (v+1)*k]) % mod
        return sum(f[l:]) % mod
        

# end-------------------------------------------------------