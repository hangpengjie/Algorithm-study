/*
 * @lc app=leetcode.cn id=1039 lang=cpp
 *
 * [1039] 多边形三角剖分的最低得分
 */
#include<bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    int minScoreTriangulation(vector<int>& values) {
        int n = values.size(), memo[n][n];
        memset(memo, -1, sizeof(memo));
        function<int(int,int)> dfs = [&](int i, int j)->int{
            if(j == i + 1) return 0;
            int &res = memo[i][j];
            if(res != -1)   return res;
            res = INT32_MAX;
            for(int k = i + 1; k < j; ++k){
                res = min(res, dfs(i, k) + dfs(k, j) + values[i] * values[k] * values[j]);
            }
            return res;
        };
        return dfs(0,n-1);
    }
};
// @lc code=end
