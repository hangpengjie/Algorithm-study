/*
 * @lc app=leetcode.cn id=1147 lang=cpp
 *
 * [1147] 段式回文
 */
#include<bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    int longestDecomposition(string text) {
        int n = text.size();
        for(int i=n-1; i>=0; --i){
            if(text[i] == text[0] && text.substr(0,n-i) == text.substr(i)){
                if(2 * i > n){
                    return 2 + longestDecomposition(text.substr(n-i, 2*i-n));
                }else if(2 * i == n){
                    return 2;
                }else{
                    return 1;
                }
            }
        }
        return 1;
    }
};
// @lc code=end

