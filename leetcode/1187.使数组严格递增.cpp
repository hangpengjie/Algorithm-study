/*
 * @lc app=leetcode.cn id=1187 lang=cpp
 *
 * [1187] 使数组严格递增
 */
#include<bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        sort(arr2.begin(),arr2.end());
        arr2.erase(unique(arr2.begin(), arr2.end()), arr2.end());   // 去重
        arr1.push_back(1e9+7);    // 添加哨兵
        arr1.insert(arr1.begin(), -1);// 添加哨兵
        vector<int> dp(arr1.size(), 1e9);
        dp[0] = 0;
        for(int i=1; i<arr1.size(); ++i){
            int j = lower_bound(arr2.begin(),arr2.end(), arr1[i]) - arr2.begin();
            for(int k=1; k<=min(i-1,j); ++k){   // 从arr1[i-1]开始替换的个数 k
                if(arr1[i-k-1] < arr2[j-k]){    // 只有arr1[i-k-1] < arr2[j-k]时才能终止替换
                    dp[i] = min(dp[i], dp[i-k-1] + k);
                }
            }
            if(arr1[i] > arr1[i-1]){    // 替换 0 个
                dp[i] = min(dp[i],dp[i-1]);
            }
        }
        int res = dp[arr1.size()-1];
        return res >= 1e9 ? -1 : res;
    }
};
// @lc code=end

