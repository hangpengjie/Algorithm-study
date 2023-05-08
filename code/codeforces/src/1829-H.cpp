
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
// https://codeforces.com/contest/1829/problem/H
// H. Don't Blame Me
// 数位DP 时间复杂度为O(n * 64) 还有更优解O(n+min(n,k)k) 不会写
#define N 200005
int MOD = 1e9+7;
int a[N],dp[64];
int count(int b){
    int ret = 0;
    while (b)
    {
        b = b & (b-1);
        ++ret;
    }
    return ret;
}
void slove(){
    int n,k,ans = 0;
    cin>>n>>k;
    memset(dp,0,sizeof(dp));
    for(int i=0; i<n; ++i){
        cin>>a[i];
    }
    for(int i=0; i<n; ++i){
        for(int j=0; j<64; ++j){
            dp[a[i] & j] = (dp[a[i] & j] + dp[j]) % MOD; 
            
        }
        ++dp[a[i]];
    }
    for(int i=0; i<64; ++i){
        if(count(i) == k){
            ans = (ans + dp[i]) % MOD;
        }
    }
    cout<<ans<<endl;
}
int main()
{
    int t;
    cin>>t;
    while(t--)slove();
}