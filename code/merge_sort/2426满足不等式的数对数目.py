from typing import *
from math import *

'''
    题目: 2426. 满足不等式的数对数目
    链接: https://leetcode.cn/problems/number-of-pairs-satisfying-inequality/description/
    思路: 归并排序求逆序对问题
'''

# start-----------------------------------------------------
class Solution:
    def numberOfPairs(self, nums1: List[int], nums2: List[int], diff: int) -> int:
        n = len(nums1)
        # 转化为nums1[i] - nums2[i] <= nums1[j] - nums2[j] + diff
        for i in range(n):
            nums1[i] -= nums2[i]
        ans = 0
        def sort_m(l,r):
            nonlocal ans
            if l >= r:
                return
            m = (l + r) // 2
            sort_m(l, m)
            sort_m(m+1, r)
            # 双指针
            i,j = l, m+1
            while j <= r:
                while i<=m and nums1[i] <= nums1[j] + diff:
                    i += 1
                ans += i - l
                j += 1
            # 归并排序
            i,j = l, m+1
            tmp = [] # 暂时存放排序后的数据
            while i <= m and j <= r:
                if nums1[i] <= nums1[j]:
                    tmp.append(nums1[i])
                    i += 1
                else:
                    tmp.append(nums1[j])
                    j += 1
            while i <= m:
                tmp.append(nums1[i])
                i += 1
            while j <= r:
                tmp.append(nums1[j])
                j += 1
            for i in range(len(tmp)):
                nums1[i + l] = tmp[i]
            return
        sort_m(0, n-1)
        return ans
s = Solution()
s.numberOfPairs([-4,-4,4,-1,-2,5],[-2,2,-1,4,4,3],1)
# end-------------------------------------------------------