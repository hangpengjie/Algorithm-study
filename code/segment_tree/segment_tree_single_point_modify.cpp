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
// 单点修改，区间查询连续最大子段和 https://www.acwing.com/problem/content/246/

// START CUT
const int N = 1e5 + 10;
int n,m;
int w[N];
struct node{
    // 该节点控制的区间[l,r]
    int l,r;
    // [l,r]区间内总和、左端连续最大值、右端连续最大值、连续最大值
    int sum,lmax,rmax,tmax;
}tr[N*4];
void pushup(node &u, node& l,node& r){
        u.sum = l.sum + r.sum;
        u.lmax = max(l.lmax, l.sum+r.lmax);
        u.rmax = max(r.rmax,r.sum+l.rmax);
        u.tmax = max(l.rmax + r.lmax, max(l.tmax, r.tmax));
};
void pushup(int u){
    pushup(tr[u],tr[u << 1], tr[u << 1 | 1]);
}
// 建树
void build(int u,int l,int r){
    // u node节点
    // [l,r] u节点管辖范围
    if(l == r) tr[u] = {l,r,w[r],w[r],w[r],w[r]};
    else{
        tr[u] = {l,r};
        int mid = (l + r) >> 1;
        build(u<<1,l,mid);
        build(u<<1|1,mid+1,r);
        pushup(u);
    }
}
// 单点修改
void modify(int u,int x,int v){
    // x 要更新的节点下标
    // v 更新后的值
    if(tr[u].l == x && tr[u].r == x) tr[u] = {x,x,v,v,v,v};
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
// END CUT



void slove(){
    cin >> n >> m;
    for(int i=1;i<=n;++i){
        cin >> w[i];
    }
    // 建树根节点u为1
    build(1,1,n);
    int op,x,y;
    while(m--){
        cin >> op >> x >> y;
        if(op == 1){
            if(x > y) swap(x,y);
            cout << query(1,x,y).tmax << endl;
        }else{
            modify(1,x,y);
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


