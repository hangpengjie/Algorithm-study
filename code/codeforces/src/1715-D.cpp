
#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
// https://codeforces.com/contest/1715/problem/D
// 1900 先构造合法序列再进行贪心算法
struct node{int d,x;};
int main()
{
    int n,q;
    cin>>n>>q;
    vector<vector<node>> g(n+1);
    vector<int> ans(n+1, (1<<30)-1);
    while(q--){
        int i,j,x;
        cin>>i>>j>>x;
        ans[i] &= x;
        ans[j] &= x;
        g[i].push_back({j,x});
        g[j].push_back({i,x});
    }
    for(int i=1; i<=n; ++i){
        int c = 0;  
        for(auto &m : g[i]){    // 当ans[m.d]中某位为1时c中该位可以为0，反之亦然
            c  |= m.x & (~ans[m.d]);
            if(m.d == i){
                c = m.x;
                break;
            }
        }
        ans[i] = c;
        cout<<c<<' ';
    }
    cout<<endl;
    

    
}