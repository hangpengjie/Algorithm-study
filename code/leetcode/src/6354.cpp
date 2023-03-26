#include <bits/stdc++.h>
//https://leetcode.cn/problems/k-items-with-the-maximum-sum/submissions/
using namespace std;
class Solution {
public:
    int pick(int &num, int *k){
        if(num > 0 && *k > 0){
            int res = 0;
            if(num > *k){
                res = *k;
                num -= *k;
                *k = 0;
            }else{
                res = num;
                *k = *k - num; 
                num = 0;
            }
            return res;
        }
        return 0;
    }
    int kItemsWithMaximumSum(int numOnes, int numZeros, int numNegOnes, int k) {
        int ans = 0;
        ans += pick(numOnes, &k);
        //cout<<k<<endl;
        ans += 0*pick(numZeros, &k);
        //cout<<k<<endl;
        ans += -1 * pick(numNegOnes, &k);
        //cout<<k<<endl;
        return ans;
    }
};
// int main()
// {
//     Solution s;
//     s.kItemsWithMaximumSum(6,6,6,13);
// }