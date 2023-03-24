/*
 * @lc app=leetcode.cn id=2488 lang=cpp
 *
 * [2488] 统计中位数为 K 的子数组
 */
/**
 * 前缀和，哈希表
 * nums[pos] = k, lmap记录pos左侧的平衡值（比k小减1，比k大加1）的数目
 * 以pos为右端点，记录从pos开始向右的平衡值，
 * 从而可以推测当k为子数组中位数时，pos左侧平衡值应该是多少
*/
#include<bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    int countSubarrays(vector<int>& nums, int k) {
        int pos = 0, n = nums.size();
        for(int i=0; i<n; ++i){
            if(nums[i] == k){
                pos = i;
                break;
            }
        }
        unordered_map<int,int> lmap;
        lmap[0] = 1;
        int t = 0;  // 平衡值
        for(int i=pos-1; i>=0; --i){
            if(nums[i] < k){
                --t;
            }else{
                ++t;
            }
            ++lmap[t];
        }
        t = 0;
        // 从pos开始枚举右端点
        int ans = 0;
        for(int i=pos; i<n; ++i){
            if(nums[i] < k){
                --t;
            }else if(nums[i] > k){
                ++t;
            }
            if(lmap.count(-t+1)){
                ans += lmap[-t+1];
            }
            if(lmap.count(-t)){
                ans += lmap[-t];
            }
        }
        return ans;

    }
};

// @lc code=end

