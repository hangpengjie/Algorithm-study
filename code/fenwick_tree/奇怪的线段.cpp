#include<bits/stdc++.h>
using namespace std;
const int N = 2e6+10,mod=1e9+7;
#define int long long
typedef long long LL;
typedef pair<int, int> PII;


// 题目链接：https://www.lanqiao.cn/problems/5131/learning/?contest_id=144
/**
 * 题目描述：给定n 和 q 代表区间总数以及查询总数，接下来 n 行，每行两个数[l,r]代表区间[l,r]
 * 接下来q行 每行a b 查询包含a但不包含b的区间总数
 * 
 * 思路：运用树状数组维护前缀和，对所有区间右端点进行从大到小排序，
 * 容斥原理：求出所有包含a的区间（这里可以用差分解决）减去所有包含a 和 b 的区间，这里就用到树状数组维护前缀和了
 * 
 * 接下来遍历区间，对op = 0的区间将其左端点加入到树状数组中，对于op=1的区间，查询[1,s]的总和，这里的总和就代表了包含a和b的区间总数了
 * 解释：因为我们是将区间按照右端点进行从大到小排序的，对于第i个区间（其op=1）前i-1个区间的右端点一定不小于第i个区间的右端点，
 * 这时前i-1个区间的s小于第i个区间的s的总和就是包含了a和b的区间总数了
*/
int n,m,k;
struct Node
{
    int s,e;
    int id,op;
}node[N];
int tr[N];
int lowbit(int x)
{
    return x & -x;
}

void add(int x, int c)  // 位置x加c
{
    for (int i = x; i <= N; i += lowbit(i)) tr[i] += c;
}

int sum(int x)  // 返回前x个数的和
{
    int res = 0;
    for (int i = x; i; i -= lowbit(i)) res += tr[i];
    return res;
}

bool cmp(const Node&n1,const Node&n2){
    if(n1.e == n2.e)
    {
        if(n1.s!=n2.s) return n1.s<n2.s;
        return n1.op<n2.op;
    }
    return n1.e>n2.e;
    
}
int res[N];
int d[N];
void solve(){
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        int l,r;
        cin>>l>>r;
        if(l>r) swap(l,r);
        d[l]++,d[r+1]--;
        node[i]={l,r,0,0};
    }
    for(int i=1;i<N;i++) d[i]+=d[i-1];
    for(int i=1;i<=m;i++)
    {
        int a,b;
        cin>>a>>b;
        res[i]=d[a];
        if(a>b) swap(a,b);
        node[++n]={a,b,i,1};
    }
    
    sort(node+1,node+1+n,cmp);
    for(int i=1;i<=n;i++)
    {
        if(node[i].op==0)
        {
            add(node[i].s,1);
        }
        else
        {
            res[node[i].id]-=sum(node[i].s);
        }
    }
    for(int i=1;i<=m;i++) cout<<res[i]<<"\n";
    
}
signed main(){
    cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
    int t=1;
   // cin>>t;
    while(t--) solve();
}