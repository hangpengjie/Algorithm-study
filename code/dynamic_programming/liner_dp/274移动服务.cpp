#include<bits/stdc++.h>
// # define MULTI
// # define INIT
using namespace std;
# define endl '\n'
# define space ' '
# define LL long long
# define PII pair<int, int>
// by hangpengjie

/**
 * 原题链接：https://www.acwing.com/problem/content/description/276/
 * 服务生有3个 f[i,x,y,z] 表示当在位置i时，三个服务生分别位于x y z 时的最小代价
 * f[i,p[i+1],y,z] = min(f[i,p[i+1],y,z], f[i,x,y,z] + c[x][p[i+1]])
 * ...
 * ...
 * 对于y z 同理
 * 这时时间复杂度为 O(M * n ^ 3) 显然是不行的
 * 考虑到所有的 i+1状态均由 i 状态转移过去,当处于i状态时，p位置为 p[i]
 * 也就是说p[i]是已知的，必有1个服务员位于p[i]
 * 那么考虑f[i,x,y]为 当一个服务员位于p[i]时，另外两个一个在x 一个在 y 此时的最小代价
 * f[i,x,y] 直接推并不容易，但是f[i,x,y]推到哪却很容易
 * p[i] -> p[i+1]    f[i+1,x,y]    = f[i,x,y] + c[p[i],p[i+1]]
 * x -> p[i+1]       f[i+1,p[i],y] = f[i,x,y] + c[x, p[i+1]]
 * y -> p[i+1]       f[i+1,x,p[i]] = f[i,x,y] + c[y, p[i+1]]
 * 
*/

const int M = 1e3 + 10;
const int N = 200 + 10;
const int INF = 0x3f3f3f3f;

int n,m;
int c[N][N];
int p[M];
int f[M][N][N];

void slove(){
    cin >> n >> m;
    for(int i=1; i<=n; ++i){
        for(int j=1; j<=n; ++j){
            cin >> c[i][j];
        }
    }
    for(int i=1; i<=m; ++i) cin >> p[i];
    p[0] = 3;
    memset(f, 0x3f, sizeof f);

    f[0][1][2] = 0;
    for(int i=0; i<m; ++i){
        for(int x = 1; x <= n; ++ x){
            for(int y=1; y<=n; ++y){
                int z = p[i];
                int v = f[i][x][y];
                if(x == y || y == z || x == z) continue;
                int u = p[i+ 1];
                f[i+1][x][y] = min(f[i+1][x][y], v + c[z][u]);
                f[i+1][z][y] = min(f[i+1][z][y], v + c[x][u]);
                f[i+1][x][z] = min(f[i+1][x][z], v + c[y][u]);
            }
        }
    }
    int res = INF;
    for(int x =1; x <= n; ++ x){
        for(int y = 1; y <= n; ++ y){
            res = min(res,f[m][x][y]);
        }
    }
    cout << res << endl;
}

# ifdef INIT
void init(){}
# endif

int main()
{
    # ifdef INIT
    init();
    # endif

    int cas = 1;
    # ifdef MULTI
    cin >> cas;
    # endif

    while (cas--){
        slove();
    }
    
}


