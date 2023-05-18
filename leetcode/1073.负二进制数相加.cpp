/*
 * @lc app=leetcode.cn id=1073 lang=cpp
 *
 * [1073] 负二进制数相加
 */
#include<bits/stdc++.h>
using namespace std;
// @lc code=start
// 模拟题
// arr1的当前位a,arr2的当前位b,进位c 三者相加 当前数 x = a +b+ c
// 当 x >= 2 时 让x-2并且进位-1 当x == -1 让x=1 进位+1具体为什么这样做可以模拟一遍看看
class Solution {
public:
    vector<int> addNegabinary(vector<int>& arr1, vector<int>& arr2) {
        int i = arr1.size() - 1, j = arr2.size() - 1;
        vector<int> ans;
        for(int c = 0; i>=0 || j>=0 || c; --i,--j){
            int a = i<0 ? 0 : arr1[i];
            int b = j<0 ? 0 : arr2[j];
            int x = a + b + c;
            c = 0;
            if(x >= 2){
                x -= 2;
                c -= 1;
            }else if(x == -1){
                x = 1;
                c += 1;
            }
            ans.push_back(x);
        }
        while(ans.size() > 1 && ans.back() == 0)   ans.pop_back();
        reverse(ans.begin(),ans.end());
        return ans;

    }
};
// @lc code=end

