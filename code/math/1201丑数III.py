from typing import *
from math import *
from functools import cache

'''
    题目: 1201. 丑数 III
    链接: https://leetcode.cn/problems/ugly-number-iii/description/
    思路: 利用二分查找 + 容斥原理
    丑数是可以被 a 或 b 或 c 整除的正整数, 设 x 是 第 k 个 丑数
    则 
            aa = lcm(a, b)
            bb = lcm(b, c)
            cc = lcm(a, c)
            dd = lcm(lcm(a, b), c)
            k = x // a + x // b + x // c - x // aa - x // bb - x // cc + x // dd
    画出图形便一目了然了
'''

# start-----------------------------------------------------
def gcd(a, b):
    return a if b == 0 else gcd(b, a % b)
def lcm(a, b):
    return a // gcd(a, b) * b
class Solution:
    def nthUglyNumber(self, n: int, a: int, b: int, c: int) -> int:
        l = 1
        r = int(1e10)
        def check(x):
            aa = lcm(a, b)
            bb = lcm(b, c)
            cc = lcm(a, c)
            dd = lcm(lcm(a, b), c)
            cnt = x // a + x // b + x // c - x // aa - x // bb - x // cc + x // dd
            return cnt >= n
        while l < r:
            m = (l + r) >> 1
            if check(m):
                r = m
            else:
                l = m + 1
        return l
        
            
# end-------------------------------------------------------