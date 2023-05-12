/*
 * @lc app=leetcode.cn id=970 lang=cpp
 *
 * [970] 强整数
 */
#include<bits/stdc++.h>
using namespace std;
// @lc code=start
// 简单的计数 主意好边界就行了
class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
        unordered_set<int> s;
        int px = 1;
        for(int i=0; i<21; ++i){
            int py=1;
            for(int j=0; j<21; ++j){
                int v = px+py;
                if(v <= bound) s.insert(v);
                else break;
                py *= y; 
            }
            if(px > bound)  break;
            px *= x;
        }
        return vector<int>(s.begin(),s.end());

    }
};
// @lc code=end

