#include<bits/stdc++.h>
using namespace std;
//https://codeforces.com/problemset/problem/1444/A
// 质因数分解   
int main()
{
    int t;
    cin>>t;
    while (t--)
    {
        long long p, q;
        cin>>p>>q;
        if(p % q){
            cout<<p<<endl;
            continue;
        }
        long long ans = 0;
        for (long long i = 2; i * i <= q; i++)
        {
            if(q % i)   continue;
            long long pp = p;
            for(q /= i; q % i == 0; q /= i) pp /= i;
            long long x = p;
            for(; pp % i == 0; pp /= i) x /= i;
            ans = max(ans, x);
        }
        if(q > 1){
            while (p % q == 0)
            {
                p /= q;
            }
            ans = max(ans,p);
            
        }
        cout<<ans<<endl;
        
    }
    
}