#include <bits/stdc++.h>
//https://leetcode.cn/problems/collect-coins-in-a-tree/
using namespace std;
class Solution {
public:
    int collectTheCoins(vector<int>& coins, vector<vector<int>>& edges) {
        int n = coins.size();
        vector<vector<int>> g(n);
        int deg[n];
        memset(deg,0,sizeof(deg));
        for(auto &e: edges){
            int x = e[0], y = e[1];
            g[x].push_back(y);
            g[y].push_back(x);
            ++deg[x];
            ++deg[y];
        }
        queue<int> q;
        // 拓扑排序进行剪枝，去除无金币子树
        for(int i=0; i<n; ++i){
            if(coins[i] == 0 && deg[i] == 1){
                q.push(i);
            }
        }
        while(!q.empty()){
            int x = q.front();
            q.pop();
            for(int y : g[x]){
                if(--deg[y] == 1 && coins[y] == 0){
                    q.push(y);
                }
            }
        }

        // 再次拓扑排序增加入队时间
        for(int i=0; i<n; ++i){
            if(coins[i] == 1 && deg[i] == 1){
                q.push(i);
            }
        }
        if(q.size() <= 1)   return 0;   // 至多一个金币直接取出
        int time[n]; memset(time, 0, sizeof(time));
        while(!q.empty()){
            int x = q.front();
            q.pop();
            for(int y : g[x]){
                if(--deg[y] == 1){
                    time[y] = time[x] + 1;
                    q.push(y);
                }
            }
        }
        int ans = 0;
        for(auto & e : edges){
            if(time[e[0]] >= 2 && time[e[1]] >= 2){
                ans += 2;
            }
        }
        return ans;
    }
};