/*
 * @lc app=leetcode.cn id=1125 lang=cpp
 *
 * [1125] 最小的必要团队
 */
#include<bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
        map<string, int> mp;
        for(int i=0; i<req_skills.size(); ++i){
            mp[req_skills[i]] = i;
        }
        vector<int> dits;
        for(auto & p : people){
            int a = 0;
            for(auto & s : p){
                a |= (1 << mp[s]);
            }
            dits.push_back(a);
        }
        int m = people.size(), n  = (1 << req_skills.size());
        long long dp[m+1][n];
        fill(dp[0], dp[0]+n, (1L<<m)-1);
        dp[0][0] = 0;
        
        for(int i=0; i<m; ++i){
            dp[i+1][0] = 0;
            for(int j=1; j<n; ++j){
                int mask = dits[i];
                auto r1 = dp[i][j];
                auto r2 = dp[i][j & ~mask] | (1L << i);
                dp[i + 1][j] = __builtin_popcountll(r1) < __builtin_popcountll(r2) ? r1 : r2;
            }
        }
        auto res = dp[m][n - 1];

        vector<int> ans;
        for (int i = 0; i < m; ++i)
            if ((res >> i) & 1)
                ans.push_back(i); // 所有在 res 中的下标
        return ans;

    }
};
// @lc code=end

