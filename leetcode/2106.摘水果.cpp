/*
 * @lc app=leetcode.cn id=2106 lang=cpp
 *
 * [2106] 摘水果
 */
#include<bits/stdc++.h>
using namespace std;

// @lc code=start
// 前缀和 两年前做过一次
class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        vector<int> pre(2e5+5,0);
        int n = pre.size(), ans = 0, start = 0;
        for(auto & fruit : fruits){
            pre[fruit[0]] = fruit[1];
        }
        ans = start = pre[startPos];
        pre[startPos] = 0;
        for(int i=startPos+1; i<n; ++i){
            pre[i] += pre[i-1];
        }
        for(int i=startPos-1; i>=0; --i){
            pre[i] += pre[i+1];
        }
        for(int i=startPos-1; i>=0 && startPos-i<=k; --i){
            int cur = pre[i] + start;
            int step = k - (startPos - i) * 2;
            // 如果剩下步数能超过n，那么是可以取到n的
            if(step > 0){
                cur += pre[min(startPos+step,n-1)];
            }
            ans = max(ans,cur);
        }
        for(int i=startPos+1; i<n && i-startPos<=k; ++i){
            int cur = pre[i] + start;
            int step = k - (i - startPos) * 2;
            // 如果剩下步数能小于0，那么是可以取到0的
            if(step > 0 ){
                cur += pre[max(startPos-step,0)];
            }
            ans = max(ans,cur);
        }
        return ans;
    }
};
// @lc code=end

