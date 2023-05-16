/*
 * @lc app=leetcode.cn id=1016 lang=cpp
 *
 * [1016] 子串能表示从 1 到 N 数字的二进制串
 */
#include<bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    bool queryString(string s, int n) {
        int len = s.size();
        if(n > 1000000) return false;
        vector<int> dist(n+1, 0);
        dist[0] = 1;
        for(int i=0; i<len; ++i){
            if(s[i] == '0') continue;
            size_t p = 0;
            for(int j=i; j<len; ++j){
                p = p * 2 + (s[j] - '0');
                if(p > n)   break;
                dist[p] = 1;
            }
        }
        return find(dist.begin(),dist.end(),0) == dist.end() ? true : false;
    }
};
// @lc code=end

