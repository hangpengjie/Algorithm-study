#include <bits/stdc++.h>
using namespace std;
// https://leetcode.cn/problems/maximum-number-of-moves-in-a-grid/
// 2684. 矩阵中移动的最大次数
// 简单的记忆化DFS 
class Solution {
public:
    int used[1001][1001];
    int dx[3] = {-1,0,1};
    int dy[3] = {1,1,1};
    int m,n;
    int slove(int x,int y, vector<vector<int>>& grid){
        if(used[x][y])  return used[x][y];
        for (int i = 0; i < 3; i++){
            int tx = x + dx[i];
            int ty = y + dy[i];
            if(tx < 0 || tx >= m || ty < 0 || ty >= n || grid[x][y] >= grid[tx][ty])  continue;
            used[x][y] = max(used[x][y], slove(tx,ty,grid)+1);
        }
        return used[x][y];
    }
    int maxMoves(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        int ans = 0;
        for(int i=0; i<m; ++i){
            ans = max(ans,slove(i,0,grid));
        }
        return ans;
    }
};