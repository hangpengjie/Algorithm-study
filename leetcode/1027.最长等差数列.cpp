/*
 * @lc app=leetcode.cn id=1027 lang=cpp
 *
 * [1027] 最长等差数列
 */
#include<bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int m[1005][1005] = {0};
        int ans = 0,n = nums.size();
        for(int i=0; i<n; ++i){
            for(int j=0; j<i; ++j){
                int diff = nums[i]-nums[j] + 500;
                m[i][diff] = max(2, m[j][diff] + 1);
                ans = max(ans,m[i][diff]);
            }
        }
        return ans;
    }
};
// @lc code=end

