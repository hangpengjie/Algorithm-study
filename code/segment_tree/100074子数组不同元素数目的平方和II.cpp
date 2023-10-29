#include<bits/stdc++.h>
# define MULTI
# define INIT
using namespace std;
# define endl '\n'
# define space ' '
# define LL long long
# define PII pair<int, int>
// by hangpengjie
/**
 * 题目: 100074. 子数组不同元素数目的平方和 II
 * 链接: https://leetcode.cn/problems/subarrays-distinct-element-sum-of-squares-ii/description/
 * 思路: 注意观察答案 
 * last[a[i]] 表示 a[i] 上次出现的位置
 * 令 j = last[a[i]] 则 [j+1, i-1] 区间内 a[i] 未出现过 那么考虑以 a[i] 为结尾的子数组
 * 1、起点在 [j+1, i-1]区间内
 *    以a[i-1]结尾的情况下 这段答案为 b^2 + c^2 + d^2 + .. ... + z^2 
 *    以a[i] 结尾的情况下 这段答案为 (b+1)^2 + (c+1) ^ 2 + (d+1) ^2 +......+(z+1)^2
 *    可以发现 增加了2*(b + c + d + ...... + z) + i-j-1
 *    那么可以使用线段树维护区间和，从而进行查询以及更新
 * 2、起点在 [1, j]区间内
 *    这点很好考虑因为 a[j] = a[i] 这些子数组的不同元素的个数与 以a[i-1]结尾的情况下一致
 * 3、起点是 i
 *    答案为 1 
*/

// START CUT
const int N = 1e5 + 10;
int a[N];
struct node{
    int l,r;
    int lazy; // 懒惰标记
    LL sum;   // 区间总和
}tr[4 * N];
void pushup(node &u, node& l,node& r){
        u.sum = l.sum + r.sum;
};
void pushup(int u){
    pushup(tr[u], tr[u << 1], tr[u << 1 | 1]);
}
void build( int l, int r, int u) {  // l:区间左端点 r:区间右端点 u:节点标号
    if (l == r) tr[u] = {l,r,0,a[l]};
    else{
        tr[u] = {l,r};
        int m = (l + r) >> 1;
        build(l, m, u << 1);
        build(m + 1, r,(u << 1) | 1);
        pushup(u);
    }
}
void pushdown(int u){
    if(tr[u].lazy){
        int m = (tr[u].l + tr[u].r) >> 1;
        tr[u << 1].sum += tr[u].lazy * (m - tr[u].l + 1);
        tr[(u << 1) | 1].sum += tr[u].lazy * (tr[u].r - m);
        
        tr[u << 1].lazy += tr[u].lazy;
        tr[(u << 1) | 1].lazy += tr[u].lazy;
        tr[u].lazy = 0;
    }
}
void update(int l, int r, int c, int u) {
    if (l <= tr[u].l && tr[u].r <= r) { // 如果区间被包含了，直接得出答案
        tr[u].sum += (tr[u].r - tr[u].l + 1) * c;
        tr[u].lazy += c; 
        return;
    }
    pushdown(u);
    int m = (tr[u].l + tr[u].r) >> 1;
    if (l <= m) update(l, r, c, u << 1); 
    if (r > m) update(l, r, c, (u << 1) | 1);
    pushup(u);  
}

node getsum(int l, int r, int u) {
    if (l <= tr[u].l && tr[u].r <= r) return tr[u];
    pushdown(u);
    int m = (tr[u].l + tr[u].r) >> 1;   // 二分寻找
    node res = {l,r,0,0};
    if (r <= m) return getsum(l, r, u << 1);
    if (l > m)  return getsum(l, r, (u << 1) | 1);
    node left = getsum(l, r, u << 1);  
    node right = getsum(l, r, (u << 1) | 1);
    pushup(res, left, right);
    return res;
}
// END CUT

class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size();
        for(int i=0; i<=2*n ; ++i){
          a[i>>1] = 0;
          tr[i].lazy = 0;
          tr[i].sum = 0;
        }
        build(1, n, 1);
        unordered_map<int,int> mp;
        LL ans = 0;
        LL mod = 1e9+7;
        LL res = 0;
        for(int i=1; i<=n; ++i){
            int x = nums[i-1];
            int j = mp.count(x) ? mp[x] : 0;
            ans += (LL)getsum(j+1,i,1).sum * 2 + i - j;
            ans %= mod;
            update(j+1,i,1,1);
            mp[x] = i;
            res = (res + ans) % mod;
        }
        return res;

    }
};

// int main(){
//     Solution s;
//     vector<int> v = {1,2,1};
//     s.sumCounts(v);
// }