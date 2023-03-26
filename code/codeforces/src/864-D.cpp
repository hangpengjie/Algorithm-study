#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    unordered_map<int, int> m;
    vector<int> ans(n+1),need, vis(n+1, 0);
    for(int i=1; i<=n; ++i){
        cin >> ans[i];
        ++m[ans[i]];
    }
    
    for(int i=1; i<=n; ++i){
        if(m[i] == 0){
            need.push_back(i);
        }
    }
    int d = 0, c= 0;
    for(int i=1; i<=n; ++i){
        if(m[ans[i]] > 1){
            if(ans[i] > need[d] && !vis[need[d]]){
                --m[ans[i]];
                ++m[need[d]];
                vis[need[d]] = 1;
                ans[i] = need[d];
                ++d;
                c++;
            }else if(ans[i] < need[d]){
                if(!vis[ans[i]]){
                    vis[ans[i]] = 1;
                }else{
                    --m[ans[i]];
                    ++m[need[d]];
                    vis[need[d]] = 1;
                    ans[i] = need[d];
                    ++d;
                    c++;    
                }
            }
        }
    }
    cout<<c<<endl;
    for(int i=1; i<=n ;++i){
        cout<<ans[i]<<" ";
    }
}