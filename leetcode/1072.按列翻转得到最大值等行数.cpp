/*
 * @lc app=leetcode.cn id=1072 lang=cpp
 *
 * [1072] 按列翻转得到最大值等行数
 */
#include<bits/stdc++.h>
using namespace std;
// @lc code=start
// 0011 1100 这两行互补，本质上是一样的，翻转前两列和后两列效果一样
class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        unordered_map<string,int> counts;
        int ans = 0;
        for(auto &m : matrix){
            string s(m.size(),0);
            for(int i=0; i<m.size(); ++i){
                s[i] = m[i] ^ m[0]; // 翻转第一个数为1的行
            }
            ans = max(ans,++counts[s]);
        }
        
        return ans;
    }
};
// @lc code=end

