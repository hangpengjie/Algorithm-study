#include<bits/stdc++.h>
using namespace std;
// https://www.acwing.com/problem/content/106/
// 中位数性质
int main()
{
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0; i<n; ++i)  cin>>a[i];
    sort(a.begin(),a.end());
    int mid = n>>1, ans = 0;

    for(int i=0; i<n; ++i)  ans += abs(a[i] - a[mid]);
    cout<<ans<<endl;
}