
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int storeWater(vector<int>& bucket, vector<int>& vat) {
        int mx = *max_element(vat.begin(),vat.end());
        if(mx == 0) return 0;
        int ans = INT32_MAX, n = bucket.size();
        // x次蓄水 一共y次增加容量
        for(int x = 1; x <= mx; ++x){
            int y = 0;
            for(int i=0; i<n; ++i){
                y += max(0, (vat[i] + x - 1) / x - bucket[i]);
            }
            ans = min(ans,x + y);
        }
        return ans;
        
    }
};