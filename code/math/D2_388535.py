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
    题目: D2. 388535 (Hard Version)
    链接: https://codeforces.com/contest/1658/problem/D2
    思路: 枚举 x 找出异或后的最大值以及最小值 保证max == r 以及 min == l 即可
'''

class Trie:
    def __init__(self) -> None:
        self.children = [None] * 2

def slove():
    l,r = MII()
    a = LII()
    g =17
    root = Trie()
    for v in a:
        head = root
        for j in range(g,-1,-1):
            if not head.children[(v >> j) & 1]:
                head.children[(v >> j) & 1] = Trie()
            head = head.children[(v >> j) & 1]
    # 最大        
    def get_1(x):
        head = root
        res = 0
        for j in range(g,-1,-1):
            c = (x >> j) & 1
            if head.children[c ^ 1]:
                res |= (1 << j)
                head = head.children[c ^ 1]
            else:
                head = head.children[c]
            if res > r:
                return False
        return res == r
    # 最小
    def get_2(x):
        head = root
        res = 0
        for j in range(g,-1,-1):
            c = (x >> j) & 1
            if head.children[c]:
                head = head.children[c]
            else:
                res |= (1 << j)
                head = head.children[c ^ 1]
            if res > l:
                return False
        return res == l

    for v in a:
        i = l ^ v
        if get_1(i) and  get_2(i): 
            print(i)
            break


    

    
    
T = II()
while T:
    T-= 1
    slove()



        

# end-------------------------------------------------------