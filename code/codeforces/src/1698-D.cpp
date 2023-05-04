
#include<bits/stdc++.h>
using namespace std;
// https://codeforces.com/contest/1698/problem/D
// 1600 D. Fixed Point Guessing
// 交互构造题 注意观察每次询问的特点
void slove()
{
    int n;
    cin>>n;
    int l = 1, r = n;
    while (l < r)
    {
        int m = l + (r - l) / 2;
        cout<<"? "<<l<<' '<<m<<endl;
        int cnt = 0;
        int a;
        for(int i=l; i<=m; ++i){
            cin>>a;
            if(a >= l && a <= m)    ++cnt;
        }
        if(cnt & 1) r = m;
        else l = m+1;
    }
    cout<<"! "<<l<<endl;
}
int main()
{
   int t;
   cin>>t;
   while (t--)
   {
        slove();
   }
   

    
}