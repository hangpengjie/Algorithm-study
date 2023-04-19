#include<bits/stdc++.h>
using namespace std;
// https://codeforces.com/contest/1725/problem/H
// 数论题
// 需要证明 concat(a, b) * concat(b, a) % 3 == concat(a%3, b%3) * concat(b%3, a%3) % 3;
// 一个数的每一位相加的和mod 3与这个数mod 3相等  15 % 3 == (1 + 5) % 3
int main()
{
    int n;
    cin>>n;
    vector<int> arr(n);
    int a[3] = {0,0,0};
    for(int i=0; i<n; ++i){
        cin>>arr[i];
        arr[i] = arr[i] % 3;
        ++a[arr[i]];
    }
    string ans(n, '0');
    int z = 0;
    if(a[0] <= n / 2){
        z = 0;
        int k = n / 2 - a[0];
        for(int i=0; i<n; ++i){
            if(arr[i] == 0) ans[i] = '1';
            else if(k){
                ans[i] = '1';
                --k;
            }
        }
    }else{
        z = 2;
        int k = n / 2;
        for(int i=0; i<n; ++i){
            if(arr[i] == 0 && k){
                ans[i] = '1';
                --k;
            } 
        }
    }
    cout<<z<<endl;
    cout<<ans<<endl;


}