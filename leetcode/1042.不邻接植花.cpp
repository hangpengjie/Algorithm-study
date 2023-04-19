/*
 * @lc app=leetcode.cn id=1042 lang=cpp
 *
 * [1042] 不邻接植花
 */
#include<bits/stdc++.h>
using namespace std;
// 参考正解：https://leetcode.cn/problems/flower-planting-with-no-adjacent/solution/liang-chong-xie-fa-ha-xi-biao-shu-zu-wei-7hm8/
// @lc code=start
class Solution {
public:
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        vector<vector<int>> g(n+1);
        for(const auto &path : paths){
            g[path[0]].push_back(path[1]);
            g[path[1]].push_back(path[0]);
        }
        vector<int> ans(n+1,0);
        ans[0] = 100;
        bool flag = false;
        int start = 1;
        do
        {
            // ans[start] = 1;
            queue<int> q;
            set<int> s;
            ans[start] = 1;
            s.insert(start);
            q.push(start);
            while (!q.empty())
            {
                int size = q.size();
                for(int i=0; i<size; ++i){
                    int c = q.front();
                    q.pop();
                    for(int j=0; j<g[c].size(); ++j){
                        if(s.find(g[c][j]) == s.end()){
                            s.insert(g[c][j]);
                            q.push(g[c][j]);
                            for(int k=1; k<=4; ++k){
                                ans[g[c][j]] = k;
                                bool ok = true;
                                for(int l=0; l<g[g[c][j]].size(); ++l){
                                    if(ans[g[g[c][j]][l]] == k){
                                        ok = false;
                                    }
                                }
                                if(ok)  break;
                            }
                           
                            
                        }
                    }
                }
            }
            

            flag = false;
            for(int i=0; i<=n; ++i) {
                if(!ans[i]){
                    flag = true;
                    start = i;
                    break;
                }
            } 
        } while (flag);
        ans.erase(ans.begin());
        return ans;
    }
};
// @lc code=end

