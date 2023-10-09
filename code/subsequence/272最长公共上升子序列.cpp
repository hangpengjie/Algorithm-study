#include<bits/stdc++.h>
// # define MULTI
// # define INIT
using namespace std;
# define endl '\n'
# define space ' '
# define LL long long
# define PII pair<int, int>
// by hangpengjie

// 例题
// https://www.acwing.com/problem/content/274/

const int N = 3010;

int a[N],b[N];
// f[i][j]表示a的前i个和b中以j结尾的最长公共上升子序列
int f[N][N];
void slove(){
    int n;
    cin >> n;
    for(int i=1; i<=n; ++i) cin >> a[i];
    for(int i=1; i<=n; ++i) cin >> b[i];
    // O(n^3)解法
    // for(int i=1; i<=n; ++i){
    //     for(int j=1; j<=n; ++j){
    //         f[i][j] = f[i-1][j];
    //         if(a[i] == b[j]){
    //             // 从0开始表示要处理一下 max(f[i][j],1) 
    //             for(int k=0; k<=j-1; ++k){
    //                 // 这里写a[i] 是因为a[i] == b[j]
    //                 if(a[i] > b[k])
    //                     f[i][j] = max(f[i][j], f[i-1][k] + 1);
    //             }
    //         }
    //     }
    // }
    for(int i=1; i<=n; ++i){
        int maxv = 1;
        for(int j=1; j<=n; ++j){
            f[i][j] = f[i-1][j];
            if(a[i] == b[j]) f[i][j] = max(maxv, f[i][j]);
            // 注意 当前for循环a[i]是不变的，而且要找的是a[i] == a[j] 所以这个写a[i]
            if(a[i] > b[j]) maxv = max(maxv,f[i][j]+1);
        }
    }
    int ans = 0;
    for(int i=1; i<=n; ++i) ans = max(ans, f[n][i]);
    cout << ans << endl;
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


