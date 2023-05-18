/*
 * @lc app=leetcode.cn id=1335 lang=cpp
 *
 * [1335] 工作计划的最低难度
 */
#include<bits/stdc++.h>
using namespace std;
// @lc code=start
// st表的应用 动态规划
class Solution {
public:
    // st表
    int f[305][10];
    void st_prework(vector<int>& jobDifficulty){
        int n = jobDifficulty.size();
        int t = log(n) / log(2) + 1;
        memset(f,0,sizeof(f));
        for(int i=1; i<=n; ++i) f[i][0] = jobDifficulty[i-1];
        for(int j=1; j<t; ++j){
            for(int i=1; i<=n-(1<<j)+1; ++i){
                f[i][j] = max(f[i][j-1],f[i+(1<<(j-1))][j-1]);  
            }
        }
    }
    int st_query(int l,int r){
        int k = log(r-l+1) / log(2);
        return max(f[l][k],f[r-(1<<k)+1][k]);
    }
    int dp[305][11];
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n = jobDifficulty.size();
        if(n < d)   return -1;
        st_prework(jobDifficulty);
        memset(dp,0x3f,sizeof(dp));
        dp[1][1] = jobDifficulty[0];
        dp[0][0] = 0;
        for(int i=2; i<=n; ++i){
            for(int j=1; j<=i && j<=d; ++j){
                for(int k=0; k<i; ++k){
                    dp[i][j] = min(dp[k][j-1] + st_query(k+1,i),dp[i][j]);
                }
            }
        }
        return dp[n][d];
    }
};
// @lc code=end

