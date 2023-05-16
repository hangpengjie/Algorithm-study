/*
 * @lc app=leetcode.cn id=1263 lang=cpp
 *
 * [1263] 推箱子
 */

#include<bits/stdc++.h>
using namespace std;
// @lc code=start
// BFS + 优先级队列
// 记录人可以到达的位置，当人到达箱子时将推动箱子，此时判断是否可以推动箱子，
// 如果可以将推动箱子，记录下推动次数，每次都优先选择最小次数向外扩展，保证最优解
// 如果不能推动箱子，则此次移动无效

class Solution {
public:
    int minPushBox(vector<vector<char>>& grid) {
        // [0] 当前状态最小推箱子步数 ([1],[2]) 人的坐标 ([3],[4]) 箱子坐标
        priority_queue<vector<size_t>,vector<vector<size_t>>, greater<vector<size_t>>> pq;
        int m = grid.size(), n = grid[0].size();
        vector<size_t> a(5,0);
        for(int i=0; i<m; ++i){
            for(int j=0; j<n; ++j){
                if(grid[i][j] == 'S'){
                    a[1] = i,a[2] = j;
                    grid[i][j] = '.';
                }else if(grid[i][j] == 'B'){
                    a[3] = i, a[4] = j;
                    grid[i][j] = '.';
                }
            }
        }
        pq.push(a);
        set<vector<size_t>> dist; // 记录经过的状态
        dist.insert({a[1],a[2],a[3],a[4]});
        int dx[4] = {0,0,1,-1};
        int dy[4] = {1,-1,0,0};
        while (!pq.empty())
        {
            auto v = pq.top();
            pq.pop();
            for(int i=0; i<4; ++i){
                vector<size_t> next_s = {v[1] + dx[i], v[2] + dy[i]};
                if(next_s[0] >= m || next_s[0] < 0 || next_s[1] >= n || next_s[1] < 0 || grid[next_s[0]][next_s[1]] == '#'){
                    continue;
                }
                vector<size_t> next_b = {v[3], v[4]};
                size_t d = v[0];
                if(next_s == next_b){
                    next_b[0] += dx[i];
                    next_b[1] += dy[i];
                    if(next_b[0] >= m || next_b[0] < 0 || next_b[1] >= n || next_b[1] < 0 || grid[next_b[0]][next_b[1]] == '#'){
                        continue;
                    }
                    ++d;
                }
                if(grid[next_b[0]][next_b[1]] == 'T'){
                    return (int) d;
                }
                if(dist.find({next_s[0],next_s[1],next_b[0],next_b[1]}) != dist.end()){
                    continue;
                }
                dist.insert({next_s[0],next_s[1],next_b[0],next_b[1]});
                pq.push({d,next_s[0],next_s[1],next_b[0],next_b[1]});
            }
            
        }
        return -1;
        
    }
};
// @lc code=end

