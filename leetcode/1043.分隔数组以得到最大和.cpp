/*
 * @lc app=leetcode.cn id=1043 lang=cpp
 *
 * [1043] 分隔数组以得到最大和
 */
#include<bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        int dp[n+1];
        dp[0] = 0;
        // dp[i] 表示子数组从 0 到 i 的最大值
        for(int i=1; i<=n; ++i){
            int ma = arr[i-1];
            dp[i] = 0;
            for(int j=i; j>0 && i-j < k; --j){
                ma = max(ma, arr[j-1]);
                dp[i] = max(dp[i], ma * (i - j + 1) + dp[j-1]);
            }
        }
        return dp[n];
    }
};
// @lc code=end

