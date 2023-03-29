/*
 * @lc app=leetcode.cn id=1641 lang=cpp
 *
 * [1641] 统计字典序元音字符串的数目
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start


class Solution {
public:
    int countVowelStrings(int n) {
        // vector<vector<int>> dp(n+1, vector<int>(5, 0));
        vector<int> d(5,1);
        for(int i=1; i<n; ++i){
            for(int i=1; i<5; ++i){
                d[i] += d[i-1];
            }
        }
        return accumulate(d.begin(),d.end(), 0);
    }
};
// @lc code=end

