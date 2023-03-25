/*
 * @lc app=leetcode.cn id=1574 lang=cpp
 *
 * [1574] 删除最短的子数组使剩余数组有序
 */
/**
 * 双指针 不会做！！
 * 分成三种情况，删除前面的，删除后面的，删除中间的
*/
#include<bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int ans = 0,n = arr.size(),j = n - 1;
        while(j - 1 >= 0 && arr[j] >= arr[j - 1])   --j;
        if(j == 0)  return 0;
        ans = j;
        for(int i=0; i<n; ++i){
            while (j < n && arr[j] < arr[i]) {
                j++;
            }
            ans = min(ans, j - i - 1);
            if (i + 1 < n && arr[i] > arr[i + 1]) {
                break;
            }
        }
        return ans;
    }
};
// @lc code=end

