#include<bits/stdc++.h>
using namespace std;
// https://codeforces.com/contest/1000/problem/D

// 组合数学 从后往前更简单
const int MOD = 998244353;
long long dp[1005];
void slove()
{
    int n;
    cin>>n;
    vector<int> arr(n+1);
    for(int i=1; i<=n; ++i){
        cin>>arr[i];
    }
    long long c[1002][1002];
     // 计算组合数并取模
    for (int i = 0; i <= 1001; i++) {
        for (int j = 0; j <= i; j++) {
            if (j == 0 || j == i) {
                c[i][j] = 1;
            } else {
                c[i][j] = (c[i-1][j] + c[i-1][j-1]) % MOD;
            }
        }
    }
    dp[n+1] = 1;
    for(int i=n; i>=1; --i){
        if(arr[i] <= 0) continue;
        for(int j=i+arr[i]; j<=n; ++j){
            dp[i] = (dp[i] + c[j-i][arr[i]] * dp[j+1]) % MOD;
        }
    }

    long long ans = 0;
    for(int i=1; i<=n; ++i){
        ans = (ans + dp[i]) % MOD;
    }
    cout<<ans<<endl;

    

}
int main()
{
    slove();
}