/*
 * @lc app=leetcode.cn id=1638 lang=cpp
 *
 * [1638] 统计只差一个字符的子串数目
 */
#include<bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    // 题解
    // https://leetcode.cn/problems/count-substrings-that-differ-by-one-character/solution/tong-ji-zhi-chai-yi-ge-zi-fu-de-zi-chuan-shu-mu-by/
    int countSubstrings(string s, string t){
        int m = s.size(), n = t.size(), ans = 0;
        for(int d = -(m - 1); d < n; ++d){
            int i = 0, j = 0;
            if(d < 0)   i = -d;
            else j = d;
            int fij = 0, gij = 0;
            for(; i < m && j < n; ++i, ++j){
                if(s[i] == t[j]){
                    ++gij;
                }else{
                    fij = gij + 1;
                    gij = 0;
                }
                ans += fij;
            }
        }
        return ans;
    }
    // 暴力写法
    // int countSubstrings(string s, string t) {
    //     int m = s.size(), n = t.size(), ans = 0;
    //     for(int i=0; i<m; ++i){
    //         for(int j=0; j<n; ++j){
    //             int diff = 0;
    //             for(int k=0; i+k < m && j+k <n; ++k){
    //                 diff += (s[i+k] != t[j+k]);
    //                 if(diff > 1)break;
    //                 if(diff == 1)   ++ans;
    //             }
    //         }
    //     }
    //     return ans;
    // }
};
// @lc code=end

