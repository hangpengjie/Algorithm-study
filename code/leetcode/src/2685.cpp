#include <bits/stdc++.h>
using namespace std;
// https://leetcode.cn/problems/count-the-number-of-complete-components/
// 2685.统计完全连通分量的数量
// 并查集的简单应用
struct UF{
    int parent[60];
    int edges[60];
    UF(int n){
        for(int i=0; i<n; ++i) {
            parent[i] = i;
            edges[i] = 0;
        }
    }
    int getEdges(int x){
        return edges[find(x)];
    }
    int find(int x){
        if(parent[x] == x)  return x;
        return parent[x] = find(parent[x]);
    }
    void merge(int x,int y){
        int tx = find(x),ty = find(y);
        if(tx == ty){
            ++edges[tx];
            return;
        }
        parent[ty] = tx;
        edges[tx] += edges[ty] + 1;
        edges[ty] = 0;
    }
};
class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        UF uf(n);
        for(auto &edge : edges){
            uf.merge(edge[0],edge[1]);
        }
        unordered_map<int,int> m;
        for(int i=0; i<n; ++i){
            ++m[uf.find(i)];
        }
        int res = 0;
        for(auto [parent,count] : m){
            if(uf.getEdges(parent) == count * (count - 1) / 2){
                ++res;
            }
        }
        return res;
    }
};