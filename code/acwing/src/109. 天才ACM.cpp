#include<bits/stdc++.h>
#define int64 long long
using namespace std;

// 109. 天才ACM
// https://www.acwing.com/problem/content/111/
// 倍增 这个题需要使用scanf 用 cin 会超时
// 这个题如果采用二分 极端境况下可能 o(n^2)
int64 a[500005],b[500005];
int64 get(int l,int r,int m){   // 左闭右开 [l, r)
    int k = 0;
    for(int i=l; i<r; ++i) b[k++] = a[i]; 
    sort(b, b+k);
    int64 sum = 0;
    int ll = 0, rr = k-1;
    for(int i=0; i<m && ll < rr; ++i,++ll,--rr){
        sum += pow(b[rr] - b[ll],2);
    }
    return sum;
}
void slove()
{
    int n,m;
    int64 t;
    scanf("%d %d %lld\n", &n, &m, &t);
    for(int i=0; i<n; ++i){
        scanf("%lld", &a[i]);
    }
    int l = 0, r = l,ans = 0;
    while (r < n)
    {
        int p = 1;
        while (p)
        {
            if(r+p <= n && get(l,r+p,m) <= t){
                r += p;
                p <<= 1;
            }else{
                p >>= 1;
            }
        }
        l = r;
        ++ans;
    }
    printf("%d\n", ans);
}
int main()
{
    int k;
    scanf("%d", &k);
    while(k--)  slove();
}