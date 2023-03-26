#include <bits/stdc++.h>
//https://leetcode.cn/problems/prime-subtraction-operation/
using namespace std;
class Solution {
public:
    // 求[1,n]的所有质数 欧拉筛
    void countPrime(int n, vector<int> &isPrime){
        vector<int> prime(n+1, 1);
        for(int i=2; i<=n; ++i){
            if(prime[i])    isPrime.push_back(i);
            for(int j=0; j <isPrime.size() && i * isPrime[j] <= n; ++j){
                prime[isPrime[j] * i] = 0;
                if(i % isPrime[j] == 0) break;
            }
        }
        return; 
    }
    bool primeSubOperation(vector<int>& nums) {
        vector<int> prime;
        countPrime(1100, prime);
        int n = nums.size();
        for(int i=n-2; i>=0; --i){
            if(nums[i] < nums[i+1]) continue;
            int sub = nums[i] - nums[i+1];
            int dex = upper_bound(prime.begin(),prime.end(),sub) - prime.begin();
            if(prime[dex] >= nums[i])   return false;
            nums[i] -= prime[dex];
        }
        return true;
    }
};

void solve()
{
    Solution s;
    vector<int> v = {4,9,6,10};
    s.primeSubOperation(v);
}