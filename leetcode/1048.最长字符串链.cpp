/*
 * @lc app=leetcode.cn id=1048 lang=cpp
 *
 * [1048] 最长字符串链
 */
#include<bits/stdc++.h>
using namespace std;
// @lc code=start
// 动态规划 注意先排序
class Solution {
public:
    int longestStrChain(vector<string>& words) {
        sort(words.begin(),words.end(),[](const string &a, const string &b)->bool{
            return a.size() < b.size();
        });
        int n = words.size(), ans = 1;
        vector<int> dp(n+1, 1);
        
        for(int i=0; i<n; ++i){
            for(int j=0; j<i; ++j){
                if(words[i].size() - words[j].size() != 1)  continue;
                int l = 0, r = 0;
                while(r < words[j].size() && words[i][l] == words[j][r]){
                    ++l,++r;
                }
                ++l;
                while(r < words[j].size() && words[i][l] == words[j][r]){
                    ++l,++r;
                }
                if(l == words[i].size() && r == words[j].size()){
                    dp[i] = max(dp[i], dp[j] + 1);
                    ans = max(ans,dp[i]);
                }
            }
        }
        return ans;
    }
};
// @lc code=end

