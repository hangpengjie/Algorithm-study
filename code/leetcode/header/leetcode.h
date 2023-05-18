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

// CUT
// ST表
int f[305][10];
void st_prework(vector<int>& arr){
    // arr从 0 开始 st表从 1 开始
    int n = arr.size();
    int t = log(n) / log(2) + 1;
    memset(f,0,sizeof(f));
    for(int i=1; i<=n; ++i) f[i][0] = arr[i-1];
    for(int j=1; j<t; ++j){
        for(int i=1; i<=n-(1<<j)+1; ++i){
            f[i][j] = max(f[i][j-1],f[i+(1<<(j-1))][j-1]);  
        }
    }
}
int st_query(int l,int r){
    int k = log(r-l+1) / log(2);
    return max(f[l][k],f[r-(1<<k)+1][k]);
}
// END CUT
    
#endif