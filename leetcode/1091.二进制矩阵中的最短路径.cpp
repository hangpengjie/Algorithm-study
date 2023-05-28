/*
 * @lc app=leetcode.cn id=1091 lang=cpp
 *
 * [1091] 二进制矩阵中的最短路径
 */
#include<bits/stdc++.h>
using namespace std;
// @lc code=start
// 简单BFS
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int dx[8] = {0,0,1,1,1,-1,-1,-1};
        int dy[8] = {1,-1,0,-1,1,1,-1,0};
        int n = grid.size();
        if(grid[0][0] || grid[n-1][n-1])    return -1;
        int step = 1;
        unordered_set<int> s;   // x*1000 + y
        queue<int> q;
        q.push(0);
        s.insert(0);
        while (!q.empty())
        {
            int size = q.size();
            for(int i=0; i<size; ++i){
                int y = q.front() % 1000;
                int x = q.front() / 1000;
                q.pop();
                if(x == n-1 && y == n-1)    return step;
                for(int j=0; j<8; ++j){
                    int tx = x + dx[j], ty = y + dy[j];
                    if(tx < 0 || tx >= n || ty < 0 || ty >= n || grid[tx][ty] || s.find(tx*1000+ty) != s.end())
                        continue;
                    q.push(tx * 1000 + ty);
                    s.insert(tx * 1000 + ty);
                }
            }
            ++step;
        }
        return -1;
        

    }
};
// @lc code=end

