#include<bits/stdc++.h>
using namespace std;
// https://codeforces.com/contest/5/problem/C
// 1900 动态规划 栈 括号匹配问题 并没有多难
int main()
{
    string s;
    cin>>s;
    int n = s.size();
    stack<int> st;
    vector<int> dp(n+1, 0);
    for(int i=0; i<n; ++i){
        if(s[i] == '('){
            st.push(i);
        }else{
            if(!st.empty()){
                dp[i+1] = dp[st.top()] + i - st.top() + 1;
                st.pop();
            }
        }
    }
    sort(dp.begin(),dp.end());
    int r1 = dp[n],r2 = 0;
    for(int i=n; i>0; --i){
        if(dp[i] == r1) ++r2;
        else break;
    }
    if(r1 == 0){
        cout<<"0 1"<<endl;
    }else{
        cout<<r1<<' '<<r2<<endl;
    }
}