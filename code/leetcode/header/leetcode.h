#ifndef LEETCODE
#define LEETCODE
// leecode header
#include<bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<long long, long long> pll;
typedef pair<ull,ull> pull;
using namespace std;
// CUT
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
// END CUT
#endif