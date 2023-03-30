/*
 * @lc app=leetcode.cn id=1637 lang=cpp
 *
 * [1637] 两点之间不包含任何点的最宽垂直面积
 */
#include<bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    static bool cmp(vector<int>& a,vector<int> &b){
        return a[0] < b[0];
    }
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        sort(points.begin(),points.end(),cmp);
        int ans = 0;
        for(int i=1; i<points.size(); ++i){
            ans = max(ans, points[i][0] - points[i-1][0]);
        }
        return ans;
    }
};
// @lc code=end

