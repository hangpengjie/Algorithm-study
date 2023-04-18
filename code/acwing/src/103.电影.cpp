#include<bits/stdc++.h>
using namespace std;
// https://www.acwing.com/problem/content/description/105/
// 离散化
void slove()
{
    int n, m;
    cin>>n;
    vector<int> sic(n);
    map<int,int> h;
    for(int i=0; i<n; ++i){
        cin>>sic[i];
        ++h[sic[i]];
    }
    cin>>m;
    vector<int> mov_1(m),mov_2(m);
    for(int i=0; i<m; ++i){
        cin>>mov_1[i];
    }
    for(int i=0; i<m; ++i){
        cin>>mov_2[i];
    }
    int ans = 0;
    for(int i=1; i<m; ++i){
        if(h[mov_1[i]] > h[mov_1[ans]] || (h[mov_1[i]] == h[mov_1[ans]] && h[mov_2[i]] > h[mov_2[ans]])){
            ans = i;
        }
    }
    cout<<ans+1<<endl;


}
int main()
{
    slove();
}