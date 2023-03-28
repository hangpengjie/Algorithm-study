/*
 * @lc app=leetcode.cn id=1092 lang=cpp
 *
 * [1092] 最短公共超序列
 */
#include<bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int m = str1.size(), n = str2.size();
        int dp[m+1][n+1];   // dp[i][j]表示str1从0到i-1与str2从0到j-1的匹配长度
        dp[0][0] = 0;
        for(int i=1; i<=m; ++i){
            dp[i][0] = i;
        }
        for(int i=1; i<=n; ++i){
            dp[0][i] = i;
        }
        for(int i=1; i<=m; ++i){
            for(int j=1; j<=n; ++j){
                if(str1[i-1] == str2[j-1]){
                    dp[i][j] = dp[i-1][j-1] + 1;
                }else{
                    if(dp[i-1][j] < dp[i][j-1]){
                        dp[i][j] = dp[i-1][j] + 1;
                    }else{
                        dp[i][j] = dp[i][j-1] + 1;
                    }
                    
                }
            }
        }
        int x = m, y = n;
        string ans;
        while(x || y){
            if(x>0 &&y>0 && str1[x-1] == str2[y-1]){
                ans += str1[x-1];
                --x;
                --y;
            }
            else if(x>0 && dp[x][y] == dp[x-1][y] + 1){
                ans += str1[x-1];
                --x;
            }else if(y>0 && dp[x][y] == dp[x][y-1] + 1){
                ans += str2[y-1];
                --y;
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
        
    }
};

// @lc code=end
