/*
 * @lc app=leetcode.cn id=1419 lang=cpp
 *
 * [1419] 数青蛙
 */
#include<bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    int minNumberOfFrogs(string croakOfFrogs) {
        char PRE['s'];  // 预处理出当前蛙鸣的前一个叫声
        const string croak = "croakc";
        for(int i=1; i<croak.size(); ++i){
            PRE[croak[i]] = croak[i-1];
        }
        int cnt['s'] = {0};
        for(auto c : croakOfFrogs){
            char pre = PRE[c];
            if(cnt[pre]){
                --cnt[pre];
                ++cnt[c];
            }else{
                if(c != 'c')    return -1;
                ++cnt[c];
            }
        }
        // 最后必须都是 k 叫声
        if(cnt['c'] | cnt['r'] | cnt['o'] | cnt['a'])   return -1;
        return cnt['k'];

    }
};
// @lc code=end

