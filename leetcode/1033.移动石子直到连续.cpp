/*
 * @lc app=leetcode.cn id=1033 lang=cpp
 *
 * [1033] 移动石子直到连续
 */
#include<bits/stdc++.h>
using namespace std;
// @lc code=start
// 好简单的分类讨论。。。
class Solution {
public:
    vector<int> numMovesStones(int a, int b, int c) {
        int r[3] = {a,b,c};
        sort(r,r+3);
        vector<int> ans(2,0);
        if(r[2] - r[0] == 2)    return ans;
        if(r[2] - r[1] <= 2 || r[1] - r[0] <= 2)    ans[0] = 1;
        else ans[0] = 2;
        ans[1] = r[2] - r[0] - 2;        
        return ans;
    }
};
// @lc code=end

