/*
 * @lc app=leetcode.cn id=1625 lang=cpp
 *
 * [1625] 执行操作后字典序最小的字符串
 */
/**
 * 有点意思
 * 当b为偶数时只能对奇数下标进行累加
 * 当b为奇数时可以对奇数进行累加也能对偶数进行累加
 * 最多轮转n次，枚举轮转次数然后记录下所有状态即可
 * b为偶数时最多n * 10 个状态
 * b为奇数时最多你n * 10 * 10 个状态
*/
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    string findLexSmallestString(string s, int a, int b) {
        int n = s.size();
        string ans = s;
        for(int i=0; i<n; ++i){
            s = s.substr(n-b) + s.substr(0, n-b);
            for(int j=0; j<10; ++j){
                for(int k=1; k<n; k+=2){
                    s[k] = (s[k] - '0' + a) % 10 + '0';
                }
                if(b&1){
                    for(int p=0; p<10; ++p){
                        for(int k=0; k<n; k+=2){
                            s[k] = (s[k] - '0' + a) % 10 + '0';
                        }
                        ans = min(ans,s);
                    }
                }else{
                    ans = min(ans, s);
                }
            }
        }
        return ans;
    }
};
// @lc code=end

