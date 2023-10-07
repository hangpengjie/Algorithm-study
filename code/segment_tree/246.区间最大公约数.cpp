#include<bits/stdc++.h>
// # define MULTI
// # define INIT
using namespace std;
# define endl '\n'
# define space ' '
# define LL long long
# define PII pair<int, int>
// by hangpengjie

// 246. 区间最大公约数 https://www.acwing.com/problem/content/247/
// 单点修改 区间查询

// 用到的知识，更相减损法 gcd(x,y) = gcd(x,y-x)
// 可以推广到 gcd(x,y,z) = gcd(x,y-x,z-y)
// b[i] = a[i] - a[i-1]
// 线段树数值d保存[l,r]的gcd
// gcd([l,r]) = gcd(a[l],query(l+1,r).d)
// a[l] = query(1,l).sum

const int N = 5e5 + 10;
int n,m;
LL w[N];
struct node{
    // 该节点控制的区间[l,r]
    int l,r;
    // 区间和以及区间最大公约数
    LL sum,d;
}tr[N*4];
// 计算最大公约数
LL gcd(LL a, LL b){
    LL c;
    while(b){
        c = a % b;
        a = b;
        b = c;
    }
    return a;
}
void pushup(node &u, node& l,node& r){
        u.sum = l.sum + r.sum;
        u.d = gcd(l.d,r.d);
};
void pushup(int u){
    pushup(tr[u],tr[u << 1], tr[u << 1 | 1]);
}
// 建树
void build(int u,int l,int r){
    // u node节点
    // [l,r] u节点管辖范围
    if(l == r) tr[u] = {l,r,w[r] - w[r-1],w[r] - w[r-1]};
    else{
        tr[u] = {l,r};
        int mid = (l + r) >> 1;
        build(u<<1,l,mid);
        build(u<<1|1,mid+1,r);
        pushup(u);
    }
}
// 单点修改
void modify(int u,int x,LL v){
    // x 要更新的节点下标
    // v 更新后的值
    if(tr[u].l == x && tr[u].r == x) tr[u] = {x,x,v+tr[u].sum,v+tr[u].sum};
    else{
        int mid = (tr[u].l + tr[u].r) >> 1;
        if(x <= mid) modify(u << 1, x, v);
        else modify(u << 1 | 1, x, v);
        pushup(u);
    }
}

// 区间查询
node query(int u,int l, int r){
    if(tr[u].l >= l && tr[u].r <= r)    return tr[u];
    int mid = (tr[u].l + tr[u].r) >> 1;
    if(r <= mid)    return query(u << 1, l, r);
    if(l > mid)     return query(u << 1 | 1, l, r);
    node left = query(u << 1, l, r);
    node right = query(u << 1 | 1, l, r);
    // 要求的节点，注意这个节点是凭空创造的而非是线段树当中任何一个节点
    node res = {l,r};
    pushup(res,left,right);
    return res;
}

void slove(){
    cin >> n >> m;
    for(int i=1;i<=n;++i){
        cin >> w[i];
    }
    // 建树根节点u为1
    build(1,1,n);
    char ch;
    int l,r;
    LL v;
    while(m--){
        cin >> ch >> l >> r;
        if(ch == 'C'){
            cin >> v;
            modify(1,l,v);
            if(r+1 <= n){
                modify(1,r+1,-v);
            }
            
        }else{
            // 前缀和相当于w[l]
            node left = query(1,1,l),right = {0,0,0,0};
            if(l+1 <= r){
                right = query(1,l+1,r);
            }
            cout << abs(gcd(left.sum,right.d)) << endl;
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


