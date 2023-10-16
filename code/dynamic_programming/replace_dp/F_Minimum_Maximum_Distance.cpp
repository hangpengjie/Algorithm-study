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

/**
 * 题目: F. Minimum Maximum Distance
 * 题目链接: https://codeforces.com/contest/1881/problem/F
 * 好e心的一道题呀，居然有 1->2 1->3 1->4...... 1->n 这样的图 第一次提交的时候直接退化成O(n^2) tle了
 * 思路: 换根DP 
 * dfs_1(cur) 的作用是找出cur子树marked vertice 到cur 的最大距离
 * dfs_2(cur) 的作用是找出整个树中marked vertice到cur的最大距离 
*/
const int N = 2e5+10;

void slove(){
    int n, k, x, u, v;
    cin >> n >> k;
    // 标记点 the marked vertices
    unordered_set<int> occ;
    for(int i=0; i<k; ++i){
        cin >> x;
        occ.insert(x);
    }
    // 图
    vector<vector<int>> g(n+1);
    vector<int> f(n+1, -1);
    for(int i=0; i<n-1; ++i){
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    auto dfs_1 = [&](auto dfs,int cur, int par)->int{
        int &res = f[cur];
        for(auto nxt : g[cur]){
            if(nxt == par)  continue;
            res = max(res, dfs(dfs, nxt, cur));
        }
        if(res > -1)    res++;
        if(occ.count(cur))  res = max(res, 0);
        return res;
    };
    dfs_1(dfs_1, 1, -1);
    auto dfs_2 = [&](auto dfs,int cur, int par, int path)->int{
        int &res = f[cur];
        res = max(res, path);
        unordered_map<int,int> cnt;
        vector<int> a; // 剔除父节点后的子节点
        for(auto nxt : g[cur]){
            if(nxt == par) continue;
            a.push_back(nxt);
        }
        // 前缀 pre[i] 表示 [0,i-1]中 f[nxt]+2 (f[nxt] != -1)的最大值
        vector<int> pre;
        int p = -INT32_MAX;
        for(auto nxt : a){
            pre.push_back(p);
            // +2 表示这个节点到其兄弟节点的距离
            if(f[nxt] != -1) p = max(p, f[nxt]+2);
        }
        p = -INT32_MAX; // 后缀
        for(int i=a.size()-1; i>=0; --i){
            int r = path+1;
            // 如果cur也是标记顶点 那么其到直接子节点的距离为 1
            if(occ.count(cur)) r = max(r, 1);
            r = max(r, pre[i]);
            r = max(r, p);
            if(f[a[i]] != -1) p = max(f[a[i]] + 2, p);
            cnt[a[i]] = r;
        }
        
        for(auto nxt : g[cur]){
            if(nxt == par)  continue;
            dfs(dfs, nxt, cur,cnt[nxt]); 
        }
        return 0;
    };
    dfs_2(dfs_2,1,-1,-INT32_MAX);
    int ans = INT32_MAX;
    for(int i=1; i<=n; ++i) ans = min(ans, f[i]);
    cout << ans << endl;
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


