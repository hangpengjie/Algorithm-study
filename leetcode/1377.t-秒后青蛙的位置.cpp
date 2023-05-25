/*
 * @lc app=leetcode.cn id=1377 lang=cpp
 *
 * [1377] T 秒后青蛙的位置
 */
#include<bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
        vector<vector<int>> g(n+1);
        vector<double> r(n+1,0);    // 记录每个节点概率
        vector<bool> used(n+1, false);
        for(auto & edge : edges){
            g[edge[0]].push_back(edge[1]);
            g[edge[1]].push_back(edge[0]);
        }
        queue<int> q;
        q.push(1);
        used[1] = true;
        r[1] = 1;
        while (!q.empty() && t--){
            int size = q.size();
            for(int i=0; i<size; ++i){
                int a = q.front();// 当前点
                q.pop();
                int cnt = 0;    // 可访问点
                for(int j=0; j<g[a].size(); ++j){
                    if(!used[g[a][j]]) ++cnt;
                }
                if(cnt == 0)    continue;   // 不可以跳到任何节点 略过即可
                double p = 1.0 / cnt;   // 当前点跳到下一点概率
                for(int j=0; j<g[a].size(); ++j){
                    if(!used[g[a][j]]){
                        used[g[a][j]] = true;
                        r[g[a][j]] = r[a] * p;
                        q.push(g[a][j]);
                    }
                }
                r[a] = 0;
            }
        }
        return r[target];

    }
};
// @lc code=end

