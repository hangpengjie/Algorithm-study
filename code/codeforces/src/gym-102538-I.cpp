
#include<bits/stdc++.h>
using namespace std;
// https://codeforces.com/gym/102538/problem/I
// I. Ignore Submasks

// 好奇怪喔 为啥把long long换成size_t就过不去呢

// 统计二进制位中1的个数
int bcount(long long x){
    int res = 0;
    while (x)
    {
        x = x & (x - 1);
        ++res;
    }
    return res;
}
int main()
{
    long long a[105];
    long long n,k,mod = 998244353;
    cin >> n >> k;
    for(int i=1; i<=n; ++i) cin >> a[i];
    long long res = 0;
    long long tot = pow(2,k);
    long long flag = 0;
    for(int i=1; i<=n; ++i){
        flag |= a[i];
        long long c = pow(2, (k - bcount(flag)));
        res = (res + ((((tot - c) % mod) * i) % mod)) % mod;
        tot = c;
    }
    cout<<res<<endl;
}