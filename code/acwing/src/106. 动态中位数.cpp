#include<bits/stdc++.h>
using namespace std;
// 106. 动态中位数
// https://www.acwing.com/problem/content/108/
// 双堆维护中位数，保证小根堆堆顶元素小于大根堆堆顶元素 两堆数量差不超过1
void slove()
{
    int d, m;
    cin>>d>>m;
    vector<int> arr(m);
    for(int i=0; i<m; ++i)  cin>>arr[i];
    cout<<d<<' '<<((m+1)/2)<<endl;
    priority_queue<int> q; // 大根堆
    priority_queue<int,vector<int>,greater<int>> p; // 小根堆
    int cnt = 0;
    for(int i=0; i<m; ++i){
        p.push(arr[i]);
        while(!q.empty() && q.top() > p.top()){
            int a = p.top(),b = q.top();
            p.pop();
            q.pop();
            p.push(b);
            q.push(a);
        }
        if(p.size() > q.size() + 1){
            q.push(p.top());
            p.pop();
        }
        if(i % 2 == 0){
            printf("%d%c",p.top(),++cnt%10==0 ? '\n':' ');//每10个数换一行
        }
    }
    if(cnt %10)
    cout<<endl;
}
int main()
{
    int t;
    cin >> t;
    while(t--)  slove();
}