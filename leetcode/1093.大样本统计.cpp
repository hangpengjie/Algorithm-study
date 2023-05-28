/*
 * @lc app=leetcode.cn id=1093 lang=cpp
 *
 * [1093] 大样本统计
 */
#include<bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<double> sampleStats(vector<int>& count) {
        vector<double> ans(5,-1);
        ans[2] =  ans[4] = 0;
        int n = count.size();
        long long  c = 0;
        for(int i=0; i<n; ++i ){
            if(count[i] && ans[0] == -1)    ans[0] = i;
            if(count[i])    ans[1] = i;
            ans[2] +=  (long long )count[i]*i;
            c += count[i];
            if(count[i] > count[ans[4]])    ans[4] = i;
        }
        ans[2] /= c;
        long long f1 = (c-1) / 2 + 1;
        long long f2 = c / 2 + 1;
        long long t = 0;
        long long d1 = -1, d2 = -1;
        for(int i=0; i<n; ++i){
            if(t+count[i] >= f1 && d1 == -1)    d1 = i;
            if(t+count[i] >= f2 && d2 == -1)    d2 = i;
            t+=count[i];
        }
        ans[3] = (1.0*d1+1.0*d2) / 2.0;
        return ans;
    }
};
// @lc code=end

