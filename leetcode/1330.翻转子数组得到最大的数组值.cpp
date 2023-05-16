/*
 * @lc app=leetcode.cn id=1330 lang=cpp
 *
 * [1330] 翻转子数组得到最大的数组值
 */
#include<bits/stdc++.h>
using namespace std;
// @lc code=start
// 数学题 需要进行分类讨论
class Solution {
public:
    int maxValueAfterReverse(vector<int>& nums) {
        int base = 0, d = 0, mn = INT32_MAX, mx = INT32_MIN, n = nums.size();
        for(int i=1; i<n; ++i){
            int a = nums[i-1], b = nums[i];
            base += abs(b-a);
            mn = min(mn,max(a,b));
            mx = max(mx,min(a,b));
            // 对l = 0 以及 r = n-1 的情况进行处理
            d = max(d, max(abs(nums[0] - b) - abs(a - b), abs(nums[n-1] - a) - abs(a - b)));
        }
        return base + max(d, 2 * (mx - mn));
    }
};
// @lc code=end

