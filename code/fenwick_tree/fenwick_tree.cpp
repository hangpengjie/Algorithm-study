#include<bits/stdc++.h>
// # define MULTI
// # define INIT
using namespace std;
# define endl '\n'
# define space ' '
# define LL long long
# define PII pair<int, int>


// by hangpengjie
// 见题 https://www.acwing.com/problem/content/243/

// START CUT 
const int N = 2e5 + 10;
// c[N]  [x - lowbit(x) + 1, x]区间和  
// n  数组总长度长度
int c[N], n;
// 计算lowbit
int lowbit(int x){
    return x & -x;
}
// 单点查询
int get(int x){
    int ret = 0;
    while(x > 0){
        ret += c[x];
        x -= lowbit(x);
    }
    return ret;
}
// 单点修改
void add(int x, int v){
    while(x <= n){
        c[x] += v;
        x = x + lowbit(x);
    }
}
// END CUT


void slove(){
    LL ans0 = 0, ans1 = 0;
    cin >> n;
    for(LL i=1; i<=n; ++i){
        int x;
        cin >> x;
        // 左边比 x 小的
        LL left = get(x-1);
        // 右边比 x 小的    
        LL right = x - 1 - left;
        ans1 += left * right;
        // 左边比  x 大的 * 右边比x大的
        ans0 += (i-1-left) * (n - x -(i-1-left));
        add(x,1);
    }
    cout << ans0 << space << ans1 << endl;
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


