/*
 * @lc app=leetcode.cn id=1023 lang=cpp
 *
 * [1023] 驼峰式匹配
 */
#include<bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        int n = queries.size();
        vector<bool> ans(queries.size(),true);
        for(int i=0; i<n; ++i){
            string &q = queries[i];
            int l = 0;
            int r = 0;
            while (l < q.size())
            {
                if(r < pattern.size() && q[l] == pattern[r]){
                    ++r;
                }else if(q[l] >= 'A' && q[l] <= 'Z'){
                    ans[i] = false;
                    break;
                }
                ++l;
            }
            if(r != pattern.size()) ans[i] = false;
            
        }
        return ans;
    }
};
// @lc code=end

