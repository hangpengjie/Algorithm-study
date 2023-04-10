#include<bits/stdc++.h>
using namespace std;
// https://codeforces.com/problemset/problem/1201/C
int main()
{
    int n, k;
    cin>>n>>k;
    vector<int> v(n,0);
    for(int i=0; i<n; ++i){
        cin>>v[i];
    }
    sort(v.begin(), v.end());
    int l = v[n>>1], r = l + k;
    while(l < r){
        int m = (r - l + 1) / 2 + l;
        long long s = 0;
        for(int i=(n>>1); i<n; ++i){
            if(s > k)   break;
            if(v[i] < m){
                s += m - v[i];
            }else{
                break;
            }
        }
        if(s > k)   r = m - 1;
        else    l = m;
    }
    
    cout<<l<<endl;
}