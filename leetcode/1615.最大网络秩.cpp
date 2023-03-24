/*
 * @lc app=leetcode.cn id=1615 lang=cpp
 *
 * [1615] 最大网络秩
 */
#include<bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<unordered_set<int>> vs(n);
        for(const auto & road : roads){
            vs[road[0]].insert(road[1]);
            vs[road[1]].insert(road[0]);
        }
        size_t ans = 0;
        for(int i=0; i<n; ++i){
            for(int j=i+1; j<n; ++j){
                if(vs[i].count(j)){
                    ans = max(ans, vs[i].size()+vs[j].size()-1);
                }else{
                    ans = max(ans, vs[i].size()+vs[j].size());
                }
            }
        }
        return ans;
    }
};
// @lc code=end

