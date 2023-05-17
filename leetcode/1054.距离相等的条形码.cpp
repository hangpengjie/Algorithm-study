/*
 * @lc app=leetcode.cn id=1054 lang=cpp
 *
 * [1054] 距离相等的条形码
 */
#include<bits/stdc++.h>
using namespace std;
// @lc code=start
// 计数统计 当某个数大于 (n+1)/2 时必须把这个数放在偶数位置上
class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        int n = barcodes.size();
        unordered_map<int,int> counts;
        for(int b : barcodes)   ++counts[b];
        vector<int> ans(n);
        int odd = 1, even = 0, half = n >> 1;
        for(auto &[x,c] : counts){
            while (c > 0 && c <= half && odd < n)
            {
                ans[odd] = x;
                --c;
                odd += 2;
            }
            while (c > 0)
            {
                ans[even] = x;
                --c;
                even += 2;
            }
        }
        return ans;
        
    }
};
// @lc code=end

