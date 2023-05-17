#include <bits/stdc++.h>
using namespace std;
// https://leetcode.cn/problems/find-the-losers-of-the-circular-game/
// 2682. 找出转圈游戏输家
// 简单模拟题
class Solution {
public:
    vector<int> circularGameLosers(int n, int k) {
        vector<int> f(n,0);
        int s = 0 ,i = 1;
        while (!f[s])
        {
            f[s] = 1;
            s = (s + i * k) % n;
            ++i;
        }
        vector<int> ans;
        for(int i=0; i<n; ++i){
            if(!f[i]) ans.push_back(i+1);
        }
        return ans;
    }
};