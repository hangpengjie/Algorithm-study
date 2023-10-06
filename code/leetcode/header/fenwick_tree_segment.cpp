#include<bits/stdc++.h>
// # define MULTI
// # define INIT
using namespace std;
# define endl '\n'
# define space ' '
# define LL long long
# define PII pair<int, int>
// by hangpengjie

// 如题：https://www.acwing.com/problem/content/248/

// START CUT
// 区间修改，区间查询
// 思路：差分 d[i] = a[i] - a[i-1]
const int N = 1e5 + 10;
long long c1[N],c2[N],n = 0;
// 计算lowbit
int lowbit(int x){
    return x & -x;
}
// 区间[l,r]增加v
void add(int l,int r,int v){
    auto f = [](int x,int v){
        long long v1 = (long long)x * v;
        while(x <= n){
            c1[x] += v;
            c2[x] += v1;
            x += lowbit(x); 
        }
    };
    f(l,v);
    f(r+1,-v);
}
long long getsum(int l,int r){
    // 计算某个数组的[1,x]区间和
    auto f = [](long long *c, int x){
        long long ret = 0;
        while(x > 0){
            ret += c[x];
            x -= lowbit(x);
        }
        return ret;
    };
    return (r + 1LL) * f(c1, r) - 1LL * l * f(c1, l-1) - (f(c2, r) - f(c2, l -1));
}
// END CUT


void slove(){
    int m;
    cin >> n >> m;
    for(int i=1; i<=n; ++i){
        int p;
        cin >> p;
        add(i,i,p);
    }
    for(int i=1; i<=m; ++i){
        char op;
        int l,r,x;
        cin >> op;
        if(op == 'Q'){
            cin >> l;
            cout << getsum(l,l) << endl;
        }else{
            cin >> l >> r >> x;
            add(l,r,x);
        }
    }
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


