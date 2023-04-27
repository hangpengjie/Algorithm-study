/*
 * @lc app=leetcode.cn id=1031 lang=cpp
 *
 * [1031] 两个非重叠子数组的最大和
 */
#include<bits/stdc++.h>
using namespace std;
// @lc code=start
// 滑动窗口 动态规划
// 在滑动过程中就可以对sum_r进行计算以及统计出左侧max_l 不需要提前计算出来
class Solution {
public:
    int slove(vector<int>& nums, int firstLen, int secondLen){
        int sum_l = accumulate(nums.begin(), nums.begin()+firstLen,0), max_l = sum_l;
        int sum_r = accumulate(nums.begin()+firstLen,nums.begin()+firstLen+secondLen,0);
        int res = max_l + sum_r;
        for(int i=firstLen, j=firstLen+secondLen; j < nums.size(); ++i,++j){
            sum_l += nums[i] - nums[i-firstLen];
            max_l = max(max_l, sum_l);
            sum_r += nums[j] - nums[j-secondLen];
            res = max(res, max_l+sum_r);
        }
        return res;
    }
    int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {
        return max(slove(nums,firstLen,secondLen),slove(nums,secondLen,firstLen));        
    }
};
// @lc code=end

