#include<bits/stdc++.h>
// # define MULTI
// # define INIT
using namespace std;
# define endl '\n'
# define space ' '
# define LL long long
# define PII pair<int, int>
// by hangpengjie

// address: https://www.acwing.com/problem/content/245/

const int N = 1e5 + 10;
int c[N], n = 0;
// 计算lowbit
int lowbit(int x){
    return x & -x;
}
int get(int x){
    int ret = 0;
    while(x > 0){
        ret += c[x];
        x -= lowbit(x);
    }
    return ret;
}
void add(int x,int v){
    while(x <= n){
        c[x] += v;
        x += lowbit(x);
    }
}
int a[N],ans[N];
void slove(){
    cin >> n;
    for(int i=2; i<=n; ++i) cin >> a[i];
    // 预处理 将所有值都设置为1
    for(int i=1; i<=n; ++i){
        c[i] += 1;
        if(i+lowbit(i) <= n){
            c[i + lowbit(i)] += c[i];
        }
    }
    for(int i=n; i>=1; --i){
        int l = 1,r = n;
        // 根据题意，可以首先确定ans[n],然后将ans[n]从{1,2,3,......,n}中剔除，
        // 随后对于每一个a[i],他的值为剔除{ans[i+1],ans[i+2],......,ans[n]}之后的集合{1,2,3,......,n}中的第a[i]+1个
        // 二分前缀和找出第一个前缀和等于 a[i] + 1的下标x，此时x即为ans[i]
        while(l < r){
            int m = (l + r) >> 1;
            int cnt = get(m);
            if(cnt - 1 >= a[i]){
                r = m;
            }else{
                l = m + 1;
            }
        }
        ans[i] = l;
        add(l,-1);
    }
    for(int i=1; i<=n; ++i){
        cout << ans[i] << endl;
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


