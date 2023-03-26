#include <bits/stdc++.h>
//https://leetcode.cn/problems/minimum-operations-to-make-all-array-elements-equal/
using namespace std;
class Solution {
public:
    vector<long long> minOperations(vector<int>& nums, vector<int>& queries) {
        vector<long long> ans(queries.size(), 0), pre(nums.size()+1, 0);
        sort(nums.begin(),nums.end());
        
        for(int i=0; i<nums.size(); ++i){
            pre[i+1] = nums[i] + pre[i];
        }
        for(int i=0; i<queries.size(); ++i){
            int dex = upper_bound(nums.begin(),nums.end(),queries[i]) - nums.begin();
            ans[i] = (long long)queries[i] * (dex) - pre[dex];  // 前半段小于等于queries[i]的
            ans[i] += pre.back() - pre[dex] - (long long)queries[i] * (nums.size() - dex);  // 后半段大于queries[i]的
        }
        return ans;
    }
};

void solve()
{
    Solution s;
    vector<int> nums = {47,50,97,58,87,72,41,63,41,51,17,21,7,100,69,66,79,92,84,9,57,26,26,28,83,38};
    vector<int> queries = {50,84,76,41,64,82,20,22,64,7,38,92,39,28,22,3,41,46,47,50,88,51,9,49,38,67,26,65,89,27,71,25,77,72,65,41,84,68,51,26,84,24,79,41,96,83,92,9,93,84,35,70,74,79,37,38,26,26,41,26};
    s.minOperations(nums,queries);
}