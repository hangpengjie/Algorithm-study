#include<bits/stdc++.h>
# define MULTI
//# define INIT
using namespace std;
#include<math.h>
# define endl '\n'
# define space ' '
# define LL long long
# define PII pair<int, int>
// by hangpengjie

// 题目: E. Block Sequence
// 题目链接: https://codeforces.com/contest/1881/problem/E
/**
 * 正南则反
 * 既然正向求DP构造不顺利，那就逆向构造DP
 * 会发现简单的多
*/
const int N = 2e5+10;
int a[N];
void slove(){
    int n;
    cin >> n;
    for(int i=0; i<n; ++i){
        cin >> a[i];
    }
    vector<int> dp(n+1, n);
    dp[n] = 0;
    for(int i=n-1; i>=0; --i){
        dp[i] = dp[i+1] + 1;
        if(i + a[i] < n){
            dp[i] = min(dp[i], dp[i+a[i] + 1]);
        }
    }
    cout << dp[0] << endl;
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


