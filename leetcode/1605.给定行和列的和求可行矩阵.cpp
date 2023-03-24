/*
 * @lc app=leetcode.cn id=1605 lang=cpp
 *
 * [1605] 给定行和列的和求可行矩阵
 */
/**
 * 贪心算法
 * 假设最后一列是每行的总和，colS数组记录每列所亏欠多少或者多余多少
 * 遍历到ans[i][j]时，从ans[i][n-1]处取值，在这个过程中要注意限制临界点，并进行更新colS
*/
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        int m = rowSum.size(), n = colSum.size();
        vector<vector<int>> ans(m, vector<int>(n, 0));
        vector<int>colS(n,0);
        for(int i=0; i<n; ++i){
            colS[i] = -colSum[i];
        }
        for(int i=0; i<m; ++i){
            ans[i][n-1] = rowSum[i];
        }
        for(int i=0; i<m; ++i){
            for(int j=0; j<n-1 && ans[i][n-1] > 0; ++j){
                if(colS[j] + ans[i][n-1] <= 0)  {
                    colS[j] += ans[i][n-1];
                    ans[i][j] = ans[i][n-1];
                    ans[i][n-1] = 0;
                }else {
                    ans[i][n-1] += colS[j];
                    ans[i][j] = -colS[j];
                    colS[j] = 0;
                }
            }
        }
        return ans;
        

    }
};
// @lc code=end

