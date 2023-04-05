#include<bits/stdc++.h>
// https://codeforces.com/contest/1701/problem/D
// 有趣的双指针 贪心 二分
// 但是写的有点复杂了 其实不需要二分，在求 L 时 L = i / (b[i] + 1) + 1 即可;
using namespace std;
typedef array<int,3> vec;
int a[500005];
int search(int i, int t, const int& n){
    int l = 1, r= n;
    while(l < r){
        int m = (l + r) >> 1;
        if(i / m <= t)  r = m;
        else l = m+1 ;
    }
    return l;
}
vec getLR(int i, int b, const int& n){
    int L = 1, R = n;
    if(b == 0){
        L = i + 1;
    }else{
        R = i / b;
        L = search(i, b, n);
    }
    return {L,R,i};
}
// 0 2 1 1 0 1 3 1
// 4 1 3 5 8 6 2 7 
// 6 1 3 4 7 5 2 8 
int main(){
    int t;
    cin >> t;
    while(t--){
        int n, b;
        cin >> n;
        vector<vec> v;
        for(int i=1; i<=n; ++i){
            cin >> b;
            v.push_back(getLR(i, b, n));
        }
        sort(v.begin(),v.end(),[](vec &a,vec &b)->bool{
            if(a[0] < b[0]) return true;
            if(a[0] > b[0]) return false;
            if(a[1] < b[1]) return true;
            return false;
        });
        set<pair<int,int>> s;   // 有序set 从小到大
        int r = 0;
        for(int i=1; i<=n; ++i){
            while(r < n && v[r][0] <= i){
                s.insert({v[r][1],v[r][2]});
                ++r;
            }
            pair<int,int> p = *s.begin();
            a[p.second] = i;
            s.erase(p);
        }
        for(int i=1; i<=n; ++i){
            cout<<a[i]<<" ";
        }
        cout << '\n';
    }
}