#include<bits/stdc++.h>
// # define MULTI
// # define INIT
using namespace std;
# define endl '\n'
# define space ' '
# define LL long long
# define PII pair<int, int>

// 例题
// https://www.acwing.com/problem/content/275/


// by hangpengjie
const int N = 2e3 + 10;
const int INF = 0x3f3f3f3f;

/**
 * 结论：最终的b数组中的数字一定在a中出现 
 * 先将a赋值给b，再将b进行排序
 * f[i][j]表示第i个数以b[j]结尾造成的代价总和
 * f[i][j] = min(f[i-1][k]) + abs(a[i] - b[j])  (k <= j)
*/ 
int n;
int a[N], b[N];
int f[N][N];

int work(){
    for(int i=1; i<=n; ++i) b[i] = a[i];
    sort(b+ 1,b + n + 1);
    for(int i=1; i<=n; ++i){
        int minv = INF;
        for (int j=1; j<=n; ++j){
            minv = min(minv, f[i-1][j]);
            f[i][j] = minv + abs(a[i] - b[j]);
        }
    }
    int res = INF;
    for(int i=1; i<=n; ++i) res = min(res, f[n][i]);
    return res;
}

void slove(){
    cin >> n;
    for(int i=1; i<=n; ++i) cin >> a[i];
    int res = work();
    reverse(a+1,a+n+1);
    res = min(res, work());
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


