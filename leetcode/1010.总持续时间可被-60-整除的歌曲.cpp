/*
 * @lc app=leetcode.cn id=1010 lang=cpp
 *
 * [1010] 总持续时间可被 60 整除的歌曲
 */
#include<bits/stdc++.h>
using namespace std;
// @lc code=start
// wa了好多次 注意数据范围time < 500
class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        unordered_map<int,int> cnt;
        for(auto t : time)  ++cnt[t];
        int ans = 0;
        for(auto &[t,c] : cnt){
            for(int k=60; k <=960; k += 60){
                if(k < 2 * t)   continue;
                if(cnt.find(k-t) == cnt.end())  continue;
                int b = cnt[k - t];
                // 注意相乘可能会超int
                // 这里两个数对相等时 实际上是求C[N][2]
                if(k == 2 * t)  ans += (long long)c * (c-1) / 2;
                else ans += (long long)b * c;
            }
        }
        return ans;
    }
};
// @lc code=end

