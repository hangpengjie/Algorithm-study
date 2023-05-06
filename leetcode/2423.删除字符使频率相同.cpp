/*
 * @lc app=leetcode.cn id=2423 lang=cpp
 *
 * [2423] 删除字符使频率相同
 */

#include<bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    bool equalFrequency(string word) {
        unordered_map<char,int> m_cnt;
        for(const char &c : word){
            ++m_cnt[c];
        }
        vector<int> cnt;
        for(auto &[_,c] : m_cnt){
            cnt.push_back(c);
        }
        sort(cnt.begin(),cnt.end());
        // 删除最小数量的一个字母或者删除最大数量的一个字母
        return cnt.size() == 1 || 
            cnt[0] == 1 && equal(cnt.begin()+2, cnt.end(),cnt.begin()+1) ||
            cnt.back() == cnt[cnt.size()-2] + 1 && equal(cnt.begin()+1, cnt.end()-1,cnt.begin());
    }
};
// @lc code=end

