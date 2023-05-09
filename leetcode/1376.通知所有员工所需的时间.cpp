/*
 * @lc app=leetcode.cn id=1376 lang=cpp
 *
 * [1376] 通知所有员工所需的时间
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
// 广度优先搜索 BFS 记录搜索过程中的时间最大值
class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<int> g[n];
        for(int i=0; i<n; ++i){
            if(headID == i)    continue;
            g[manager[i]].push_back(i);
        }
        int time = 0, cnt = 1;
        queue<pair<int,int>> q;
        q.push({headID,0});
        while (!q.empty())
        {
            int size = q.size();
            for(int i=0; i<size; ++i){
                auto [c,t] = q.front();
                time = max(time,t);
                for(int j=0; j<g[c].size(); ++j){
                    q.push({g[c][j],t+informTime[c]});
                }
                q.pop();
            }
        }
        return time;
    }
};
// @lc code=end

