整数拆分问题<br/>

给定一个正整数 n ，将其拆分为 k 个 正整数 的和（ k >= 2 ），并使这些整数的乘积最大化。返回你可以获得的最大乘积 。

题目: 
- [343. 整数拆分](https://leetcode.cn/problems/integer-break/description/)

- [1808. 好因子的最大数目](https://leetcode.cn/problems/maximize-number-of-nice-divisors/description/)

解法:

$f(x) 表示把n尽可能分成x时的时候所有数的乘积，显然可以把n分成\frac{n}{x}此时f(x) = x^{\frac{n}{x}}$

$f(x) = x^{\frac{n}{x}}=e^{\frac{nln(x)}{x}}$

$令h(x)=\frac{ln(x)}{x}$

$则{h}'(x)=\frac{1-ln(x)}{x^2}$

$可以得知{h}'(e)=0当x < e时,{h}'(x) > 0, x > e 时 {h}'(x) < 0,x = e时h(x) 最大$

$\frac{h(2)}{h(3)}=\frac{ln(8)}{ln(9)}<1$

$所以f(3)>f(2)则应该给n分更多的3$

代码:

```python
from typing import *
from math import *
from functools import cache
from queue import *
from heapq import *
from bisect import bisect_left
# start-----------------------------------------------------

class Solution:
    def maxNiceDivisors(self, primeFactors: int) -> int:
        ans = 0
        mod = int(1e9+7)
        q = primeFactors // 3
        r = primeFactors % 3
        # 快速幂
        def qpow(a,b,m):
            res = 1
            while b:
                if b & 1:
                    res = res * a % m
                b >>= 1
                a = a * a % m
            return res
       
        if r == 0:   # 余数为 0 
            ans = qpow(3, q, mod)
        elif r == 1: # 余数为 1 分配 2*2 比 3*1更好
            ans = qpow(3, q-1, mod) * 4
        else:        # 余数为 2 
            ans = qpow(3, q, mod) * 2
        return ans % mod

# end-------------------------------------------------------

```



