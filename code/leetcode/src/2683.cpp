#include <bits/stdc++.h>
using namespace std;
// https://leetcode.cn/problems/neighboring-bitwise-xor/
// 2683. 相邻值的按位异或
// 简单的模拟位运算
class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int n = derived.size(),cur = 0;
        for(int i=0; i<n-1; ++i){
            if(derived[i]){   //o[i+1] != o[i]
                cur = cur ^ 1;
            }
        }
        return (cur ^ 0) == derived[n-1];
    }
};