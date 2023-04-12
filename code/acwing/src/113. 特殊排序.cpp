#include<bits/stdc++.h>
using namespace std;
// https://www.acwing.com/problem/content/115/
class Solution {
public:
    bool compare(int a, int b);
    void qsort(vector<int> &res, int l, int r){
        if(l < r){
            int k = sort(res, l, r);
            qsort(res, l, k-1);
            qsort(res, k+1, r);
        }
    }
    int sort(vector<int> &res, int l, int r){
        int k = (rand() % (r - l + 1)) + l;
        swap(res[l], res[k]);
        k = res[l];
        while (l < r)
        {
            while(l < r && !compare(res[r], k)) --r;
            if(l < r)   res[l] = res[r];
            while(l < r && compare(res[l], k))  ++l;
            if(l < r)   res[r] = res[l];  
        }
        res[l] = k;
        return l;
    }
    vector<int> specialSort(int N) {
        vector<int> res(N);
        srand(time(nullptr));
        for(int i = 0; i < N; ++i)  res[i] = i + 1;
        qsort(res, 0, N-1);
        return res;
    }
};
int main()
{
    Solution s;
     s.specialSort(6);
}