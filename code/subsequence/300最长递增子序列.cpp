#include<bits/stdc++.h>
// # define MULTI
// # define INIT
using namespace std;
# define endl '\n'
# define space ' '
# define LL long long
# define PII pair<int, int>
// by hangpengjie

// 例题
// https://leetcode.cn/problems/longest-increasing-subsequence/

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> d;
        for(int num : nums){
            if(d.empty() || num > d.back()) {
                d.push_back(num);
                continue;
            }
            int l = 0,r = d.size()-1;
            while(l < r){
                int m = (l + r) >> 1;
                if(num > d[m]){
                    l = m + 1;
                }else{
                    r = m;
                }
            }
            d[l] = num;
        }
        return d.size();
    }
};