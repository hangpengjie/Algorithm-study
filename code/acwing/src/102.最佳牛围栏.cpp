#include<bits/stdc++.h>
using namespace std;
int a[100003]; double sum[100003];

int main(){
    int n, f;
    double l = 0, r = 0;
    cin >> n >> f;
    for(int i=1; i<=n; ++i){
        cin >> a[i];
        r = max(r, (double)a[i]);
    }
    function<bool(double)> check = [&](double avg)->bool{
        for(int i=0; i<=n; ++i){
            sum[i] = sum[i-1] + a[i] - avg;
        }
        double mv = 0;
        for(int i=0, j=f; j<=n; ++j, ++i){
            mv = min(mv, sum[i]);
            if(sum[j] - mv >= 0)    return true;
        }
        return false;
    };
    while(r - l > 1e-5){
        double mid = (r + l) / 2;
        if(check(mid)){
            r = mid;
        }else{
            l = mid;
        }
    }
    // 这里必须返回 r * 1000 
    // r - l 大概是1e-5  若返回 l * 1000得到的值可能会比答案小1
    printf("%d\n",(int)(r*1000));
    
}