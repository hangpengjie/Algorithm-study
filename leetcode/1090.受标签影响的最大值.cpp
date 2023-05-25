/*
 * @lc app=leetcode.cn id=1090 lang=cpp
 *
 * [1090] 受标签影响的最大值
 */
#include<bits/stdc++.h>
using namespace std;
// @lc code=start
// 计数 排序
class Solution {
public:
    int largestValsFromLabels(vector<int>& values, vector<int>& labels, int numWanted, int useLimit) {
        int n = values.size();
        vector<pair<int,int>> v;
        unordered_map<int,int> m;
        for(int i=0; i<n; ++i){
            v.push_back({values[i],labels[i]});
            m[labels[i]] = useLimit;
        }
        int ans = 0,d = 0;
        sort(v.rbegin(),v.rend());
        for(int i=0; i<numWanted; ++i){
            while (d < n && !m[v[d].second]){++d;}
            if(d < n){
                ans += v[d].first;
                --m[v[d++].second];
            }
        }
        return ans;
    }
};
// @lc code=end
