#include<bits/stdc++.h>
//# define MULTI
//# define INIT
using namespace std;
#include<math.h>
# define endl '\n'
# define space ' '
# define LL long long
# define PII pair<int, int>
// by hangpengjie

/**
 * 题目: 278. 数字组合
 * 链接: https://www.acwing.com/problem/content/280/
 * 思路: 01背包 dp[i][j] 表示前i个数和为j的种类数
*/

void slove(){
    int n, m;
    cin >> n >> m;
    vector<int> a(n+1,0);
    for(int i=1; i<=n; ++i) cin >> a[i];
    vector<vector<int>> dp(n+1,vector<int>(m+1,0));
    dp[0][0] = 1;
    for(int i=1; i<=n; ++i){
        dp[i][0] = 1;
        for(int j=1; j<=m; ++j){
            dp[i][j] += dp[i-1][j];
            if(j >= a[i]) dp[i][j] += dp[i-1][j-a[i]];
        }
    }
    cout << dp[n][m] << endl;
}

# ifdef INIT
void init(){
  
}
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


