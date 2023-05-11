
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
// https://codeforces.com/contest/803/submit
// F. Coprime Subsequences
// 2000 数论+计数
// 注意观察哪些组合不应加入到计算当中
// 倍数之间的组合不能加入到计算结果！ 其他组合是可以的！
#define N 1000006
int MOD = 1e9 + 7;
long long dp[N], cnt[N], p[N];
int main()
{
    int n;
    cin>>n;
    p[0] = 1;
    for(int i=1; i<=n; ++i){
        int a;
        cin>>a;
        ++cnt[a];
        p[i] = (p[i-1] << 1) % MOD;
    }
    for(int i = N-2; i >= 1; --i){
        int c = 0;
        for(int j=i; j<N; j+=i){
            c += cnt[j];
        }
        dp[i] = (p[c] - 1 + MOD) % MOD;
        for(int j=2*i; j<N; j+=i){
            dp[i] = (dp[i] - dp[j] + MOD) % MOD;
        } 
    }
    cout<<dp[1]<<endl;
}