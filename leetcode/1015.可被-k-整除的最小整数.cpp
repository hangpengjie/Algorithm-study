/*
 * @lc app=leetcode.cn id=1015 lang=cpp
 *
 * [1015] 可被 K 整除的最小整数
 */
#include<bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    int smallestRepunitDivByK(int k) {
        if(k % 2 == 0 || k % 5 == 0)    return -1;
        int x = 1 % k;
        for(int i=1; ; ++i){
            if(x == 0)  return i;
            x = (x * 10 + 1) % k; 
        }
        return -1;
    }
};
// @lc code=end

