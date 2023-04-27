/*
 * @lc app=leetcode.cn id=1105 lang=cpp
 *
 * [1105] 填充书架
 */
#include<bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        int dp[1005] = {0},n = books.size();
        for(int i=0; i<n; ++i){
            dp[i+1] = 1e9;
            int h = 0, w = 0;
            for(int j=i; j>=0; --j){
                w += books[j][0];
                if(w > shelfWidth)  break;
                h = max(h, books[j][1]);
                dp[i+1] = min(dp[i+1], dp[j] + h); 
            }
        }
        return dp[n];
    }
};
// @lc code=end

