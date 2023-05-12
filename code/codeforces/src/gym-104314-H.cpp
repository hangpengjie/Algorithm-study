#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
// https://codeforces.com/gym/104314/problem/H
// 思维题
// 细心！！
int main()
{
    int n;
    cin>>n;
    set<pair<int,int>> ss,de; 
    int cnt_l[105],cnt_r[105];
    function<void()> del = [&](){
        while (!de.empty())
        {
            auto it = de.begin();
            --cnt_l[it->first];
            --cnt_r[it->second];
            ss.erase((*it));
            de.erase(it);
        }
    };
    memset(cnt_l,0,sizeof(cnt_l));
    memset(cnt_r,0,sizeof(cnt_r));
    for(int i=0; i<n; ++i){
        int l,r;
        cin>>l>>r;
        ss.insert({l,r});
        ++cnt_l[l];
        ++cnt_r[r];
    }
    for(auto c : ss){
        // 此处不应该直接照搬右侧处理情况，
        // 细想一下“我不知道奖品card，你也不知道奖品card”,这句话对于说者和听着来说是不同的！！！
        // 对于说者来说左侧计数值为1的一定不是最终card
        // 对于听者来说右侧计数值为1的card左侧值为leftVal，所有card当中左侧值为leftVal的一定不是最终card
        if(cnt_l[c.first] == 1){
            // for(auto d : ss){
            //     if(d.second == c.second)    de.insert(d);
            // }
            de.insert(c);
        }
        if(cnt_r[c.second] == 1){
            for(auto d : ss){
                if(d.first == c.first)    de.insert(d);
            }
        }
    }
    del();
    for(auto c : ss){
        if(cnt_r[c.second] > 1){
            for(auto d : ss){
                if(d.second == c.second)    de.insert(d);
            }
        }
    }
    del();
    for(auto c : ss){
        if(cnt_l[c.first] > 1){
            for(auto d : ss){
                if(d.first == c.first)    de.insert(d);
            }
        }
    }
    del();
    auto res = ss.begin();
    cout<<res->first<<" "<<res->second<<endl;

}