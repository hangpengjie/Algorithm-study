#include "../header/leetcode.h"
//https://leetcode.cn/problems/make-sum-divisible-by-p/
// can't slove by myself
class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n = nums.size(), ans = n;
        vector<int> s(n+1, 0);
        for(int i=0; i<n; ++i){
            s[i+1] = (s[i] + nums[i]) % p;
        }
        int x = s[n];
        if(x == 0)  return 0;
        unordered_map<int,int> m;
        for(int i=0; i<=n; ++i){
            m[s[i]] = i;
            auto it = m.find((s[i] - x + p) % p);
            if(it != m.end()){
                ans =  min(ans, i-it->second);
            }
        }
        return ans < n ? ans : -1;


    }
};