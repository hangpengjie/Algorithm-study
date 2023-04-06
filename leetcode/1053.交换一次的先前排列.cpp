/*
 * @lc app=leetcode.cn id=1053 lang=cpp
 *
 * [1053] 交换一次的先前排列
 */
#include<bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<int> prevPermOpt1(vector<int>& arr) {
        int n = arr.size();
        for(int i = n - 2; i >= 0; --i){
            if(arr[i] > arr[i + 1]){
                int j = i + 1;
                while(j + 1 < n && arr[j + 1] < arr[i]) ++j;
                while(arr[j - 1] == arr[j]) --j;
                swap(arr[i], arr[j]);
                break;
            }
        }
        return arr;
    }
};
// @lc code=end

