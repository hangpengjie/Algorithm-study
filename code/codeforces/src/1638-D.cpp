
#include<bits/stdc++.h>
using namespace std;
// https://codeforces.com/contest/1638/problem/D
// 2000 D. Big Brush
// 贪心构造题 dfs 从最后一个色块开始复原数组 直至全为0 
// 一定不能用 endl 会超时
int a[1005][1005];
struct node
{
    int x,y,c;
}v[1030000];

// vector<tuple<int,int,int>> v(1000009);
int m,n,cnt;
void dfs(int x,int y){
    if(x < 1 || x >= m || y < 1 || y >= n)  return;
    int color = 0;
    for(int i=x; i <=x+1; ++i){
        for(int j=y; j<=y+1; ++j){
            if(a[i][j]){
                if(color && a[i][j] != color) return;
                color = a[i][j];
            }
        }
    }
    if(color){
        v[cnt++] = {x,y,color};
        a[x][y] = a[x+1][y] = a[x][y+1] = a[x+1][y+1] = 0;
        for(int i = x-1; i<=x+1; ++i){
            for(int j=y-1; j<= y+1; ++j){
                dfs(i,j);
            }
        }  
    }
}

int main()
{
    cin>>m>>n;
    for(int i=1; i<=m; ++i){
        for(int j=1; j<=n; ++j){
            cin>>a[i][j];
        }
    }
    for(int i=1; i<=m; ++i){
        for(int j=1; j<=n; ++j){
            dfs(i,j);
        }
    }
    for(int i=1; i<=m; ++i){
        for(int j=1; j<=n; ++j){
            if(a[i][j]){
                cout<<"-1"<<endl;
                return 0;
            }
        }
    }
    cout<<cnt<<"\n";
    for(int i=cnt-1; i>=0; --i){
        cout<< v[i].x <<" "<< v[i].y <<" "<< v[i].c<<"\n";
    }
    


}