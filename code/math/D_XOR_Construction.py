if 1:
    standard_input, packages, output_together = 1, 1, 1
    dfs, hashing, read_from_file = 0, 0, 0
    de = 1
 
    if standard_input:
        import io, os, sys
        input = lambda: sys.stdin.readline().strip()
 
        inf = float('inf')
 
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
 
        def LFI():
            return list(map(float, input().split()))
 
        def GMI():
            return map(lambda x: int(x) - 1, input().split())
 
        def LGMI():
            return list(map(lambda x: int(x) - 1, input().split()))
 
    if packages:
        from io import BytesIO, IOBase
        import math
 
        import random
        import os
 
        import bisect
        import typing
        from collections import Counter, defaultdict, deque
        from copy import deepcopy
        from functools import cmp_to_key, lru_cache, reduce
        from heapq import heapify, heappop, heappush, heappushpop, nlargest, nsmallest
        from itertools import accumulate, combinations, permutations, count, product
        from operator import add, iand, ior, itemgetter, mul, xor
        from string import ascii_lowercase, ascii_uppercase, ascii_letters
        from typing import *
        BUFSIZE = 4096
 
    if output_together:
        class FastIO(IOBase):
            newlines = 0
 
            def __init__(self, file):
                self._fd = file.fileno()
                self.buffer = BytesIO()
                self.writable = "x" in file.mode or "r" not in file.mode
                self.write = self.buffer.write if self.writable else None
 
            def read(self):
                while True:
                    b = os.read(self._fd, max(os.fstat(self._fd).st_size, BUFSIZE))
                    if not b:
                        break
                    ptr = self.buffer.tell()
                    self.buffer.seek(0, 2), self.buffer.write(b), self.buffer.seek(ptr)
                self.newlines = 0
                return self.buffer.read()
 
            def readline(self):
                while self.newlines == 0:
                    b = os.read(self._fd, max(os.fstat(self._fd).st_size, BUFSIZE))
                    self.newlines = b.count(b"\n") + (not b)
                    ptr = self.buffer.tell()
                    self.buffer.seek(0, 2), self.buffer.write(b), self.buffer.seek(ptr)
                self.newlines -= 1
                return self.buffer.readline()
 
            def flush(self):
                if self.writable:
                    os.write(self._fd, self.buffer.getvalue())
                    self.buffer.truncate(0), self.buffer.seek(0)
 
        class IOWrapper(IOBase):
            def __init__(self, file):
                self.buffer = FastIO(file)
                self.flush = self.buffer.flush
                self.writable = self.buffer.writable
                self.write = lambda s: self.buffer.write(s.encode("ascii"))
                self.read = lambda: self.buffer.read().decode("ascii")
                self.readline = lambda: self.buffer.readline().decode("ascii")
 
        sys.stdout = IOWrapper(sys.stdout)
 
    if dfs:
        from types import GeneratorType
 
        def bootstrap(f, stack=[]):
            def wrappedfunc(*args, **kwargs):
                if stack:
                    return f(*args, **kwargs)
                else:
                    to = f(*args, **kwargs)
                    while True:
                        if type(to) is GeneratorType:
                            stack.append(to)
                            to = next(to)
                        else:
                            stack.pop()
                            if not stack:
                                break
                            to = stack[-1].send(to)
                    return to
            return wrappedfunc
 
    if hashing:
        RANDOM = random.getrandbits(20)
        class Wrapper(int):
            def __init__(self, x):
                int.__init__(x)
 
            def __hash__(self):
                return super(Wrapper, self).__hash__() ^ RANDOM
 
    if read_from_file:
        file = open("input.txt", "r").readline().strip()[1:-1]
        fin = open(file, 'r')
        input = lambda: fin.readline().strip()
        output_file = open("output.txt", "w")
        def fprint(*args, **kwargs):
            print(*args, **kwargs, file=output_file)
 
    if de:
        def debug(*args, **kwargs):
            print('\033[92m', end='')
            print(*args, **kwargs)
            print('\033[0m', end='')

# start-----------------------------------------------------

'''
    题目: D. XOR Construction
    链接: https://codeforces.com/problemset/problem/1895/D
    思路: 
        1、经过观察可以看出对于 i > 1 时 b[i] = b[1] ^ ( a[1] ^ ... ^ a[i-1])
           i > 1 时 令b[i] = b[1] ^ ( a[1] ^ ... ^ a[i-1])
           题目确定对于每个数组a都可以构造出一个数组b, 那么我们可以从[0,n-1]遍历一遍确定哪个是b[1]
           考虑使用trie找出b[1] ^ b[i] (1 < i <= n) 的最大值,如果最大值等于n-1,那么剩下的[0,n-2]也就确定了！

        2、对于[0,n-1]这n个数可以发现第i位上的0永远是大于等于1的,毕竟先有0后有1
           i > 1 时 令b[i] = b[1] ^ ( a[1] ^ ... ^ a[i-1])
           那么可以枚举b[i] (1 < i <= n)中的第 i 位 判断其1的个数是否大于0的个数,如果大于,那么b[1]的第i位需要为1
           从而将第i位调整为0的个数大于等于1

'''
def slove():
    n = II()
    a = LII()
    b = [0] * (n )
    for i in range(1, n):
        b[i] = b[i-1] ^ a[i-1]
    for i in range(20):
        d1,d2 = 0 ,0
        for j in range(1, n):
            if (b[j] >> i) & 1:
                d1 += 1
            else:
                d2 += 1
        if d1 > d2:
            b[0] |= (1  << i) 
    for i in range(1, n):
        b[i] = b[i] ^ b[0]
    print(*b)
    
    
T = 1
while T:
    T-= 1
    slove()



        

# end-------------------------------------------------------