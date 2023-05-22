/*
 * @lc app=leetcode.cn id=1079 lang=cpp
 *
 * [1079] 活字印刷
 */

#include<bits/stdc++.h>
using namespace std;
// @lc code=start

const int MX = 8;
int c[MX][MX];
// 预处理得到组合数
int init = [](){
    for(int i=0; i<MX; ++i){
        c[i][0] = c[i][i] = 1;
        for(int j=1; j<i; ++j){
            c[i][j] = c[i-1][j-1] + c[i-1][j];
        }
    }
    return 0;
}();
class Solution {
public:
    int numTilePossibilities(string tiles) {
        unordered_map<char,int> counts;
        for(char t : tiles) ++counts[t];
        // f[i][j] -> 前i种字母组合得到长度为j的字符串的数量
        int n = tiles.size(),m = counts.size(), f[m+1][n+1];
        memset(f, 0, sizeof(f));
        f[0][0] = 1;
        int i=1;
        for(auto &[_,cnt] : counts){
            for(int j=0; j<=n; ++j){
                for(int k=0; k<=j && k <= cnt; ++k){
                    f[i][j] += f[i-1][j-k] * c[j][k];
                }
            }
            ++i;
        }
        // 长度至少为1
        return accumulate(f[m]+1, f[m]+n+1, 0);
    }
};
// @lc code=end

