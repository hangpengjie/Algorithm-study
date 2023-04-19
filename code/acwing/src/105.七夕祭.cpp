#include<bits/stdc++.h>
using namespace std;
// https://www.acwing.com/problem/content/107/
// 均摊纸牌 中位数 环形均摊纸牌 贪心 行列不相关
// 要推导出环形均摊纸牌的公式 可以发现这个公式跟104.货仓选址一样利用中位数的性质解题
#define N  100005
int x[N], y[N], f[N];
long long xsum = 0, ysum = 0;
long long slove(int arr[N], int n, int avg){
    f[0] = 0;
    for(int i=1; i<=n; ++i){
        f[i] = f[i-1] + arr[i] - avg;
    }
    sort(f+1, f+1+n);
    long long ans = 0;
    for(int i=1; i<=n; ++i){
        ans += abs(f[i] - f[(n+1)>>1]);
    }
    return ans;
}
int main()
{
    int n,m,t,sum;
    cin>>n>>m>>t;
    sum = n * m;
    
    for(int i=1; i<=t; ++i){
        int a,b;
        cin>>a>>b;
        ++x[a];
        ++y[b];
        ++xsum;
        ++ysum;
    }
    if(t % n == 0 && t % m == 0){
        cout<<"both "<<(slove(x,n, xsum/n) + slove(y,m, ysum/m))<<endl;

    }else if(t % n == 0){
        cout<<"row "<<(slove(x,n,xsum/n))<<endl;
    }else if(t % m == 0){
        cout<<"column "<<(slove(y,m,ysum/m))<<endl;
    }else{
        cout<<"impossible\n";
    }

    
}