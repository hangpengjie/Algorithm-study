/*
 * @lc app=leetcode.cn id=1041 lang=cpp
 *
 * [1041] 困于环中的机器人
 */
#include<bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    bool isRobotBounded(string instructions) {
        set<pair<int,int>> s;
        s.insert({0,0});
        int x = 0, y = 0;
        //               北    西     南     东
        int dir[4][2] = {{0,1},{-1,0},{0,-1},{1,0}};
        int cur = 0;    // 北
        for(int i=0; i<instructions.size(); ++i){
            char &c = instructions[i];
            if(c == 'G')    x += dir[cur][0], y += dir[cur][1];
            else if(c == 'L')    cur = (cur + 1) % 4;
            else     cur = (cur + 3) % 4;
        }
        // 只要执行完一次之后方向不朝北，那么一定会陷入循环！
        if(cur != 0 || (x == 0 && y == 0)){
            return true;
        }else{
            return false;
        }

    }
};
// @lc code=end

