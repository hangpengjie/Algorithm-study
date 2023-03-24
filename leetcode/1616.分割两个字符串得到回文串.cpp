/*
 * @lc app=leetcode.cn id=1616 lang=cpp
 *
 * [1616] 分割两个字符串得到回文串
 */
/**
 * 很有意思的双指针，需要主意好边界！！
*/
#include<bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    // 从中心扩展能到达的左端点最小值
    // 偶数情况下不存在回文串返回INT32_MAX
    int getPreOption(string &a){
        int n = a.size();
        int l = (n - 1) >> 1, r = n >> 1;
        int ans = INT32_MAX;
        while(l >= 0){
            if(a[l] != a[r]){
                return ans;
            }else{
                ans = l;
            }
            --l,++r;
        }
        return ans;
    }
    bool checkPalindromeFormation(string a, string b) {
        int pa = getPreOption(a), pb = getPreOption(b), n = a.size();
        if(pa == 0 || pb == 0)  return true;
        bool ta = true, tb = true;
        
        for(int i=0; i < (n>>1); ++i){
            if(ta){
                if(a[i] != b[n-1-i]){
                    ta = false;
                }
                else if(i+1 > n-i-2)   return true;
                else if(pb <= i+1 || pa <= i+1)  return true;  
            }
            if(tb){
                if(b[i] != a[n-1-i]){
                    tb = false;
                }
                else if(i+1 > n-i-2)   return true;
                else if(pa <= i+1 || pb <= i+1)  return true;
            }
        }
        return false;
    }
};
// @lc code=end