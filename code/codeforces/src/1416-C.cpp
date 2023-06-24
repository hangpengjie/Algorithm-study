#include<bits/stdc++.h>
using namespace std;
#define ll long long
// C. XOR Inverse
// https://codeforces.com/problemset/problem/1416/C
// tree greedy bitmasks
// 注意使用long long 避免精度丢失
vector<ll> vec(30);
vector<ll> tot(30);
void slove(vector<int> a,int b){
    if(b == -1 || a.empty())    return;
    ll sz = a.size();  // a 的长度
    ll cn = 0; // 逆序对个数
    vector<int> ov; // 1
    vector<int> zv; // 0
    for(int i=sz - 1; i >=0; --i){
        if(a[i] & (1<<b)){
            vec[b] += cn;
            ov.push_back(a[i]);
        }else{
            ++cn;
            zv.push_back(a[i]);
        }
    }
    tot[b] += cn * (sz - cn);
    reverse(ov.begin(),ov.end());
    reverse(zv.begin(),zv.end());
    slove(ov,b-1);
    slove(zv,b-1);
}
int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0; i<n; ++i){
        cin>>a[i];
    }
    slove(a,29);
    ll bc = 0,x = 0;
    for(int i=0; i<30; ++i){
        // 如果vec[i] > tot[i] - vec[i] 说明原始状态下逆序对比较多，需要取反来减少逆序对
        if(vec[i] > tot[i] - vec[i])    x += (1<<i);
        bc += min(vec[i], tot[i]-vec[i]);
    }
    cout<<bc<<" "<<x<<endl;
}