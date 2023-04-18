#include<bits/stdc++.h>
using namespace std;
// https://codeforces.com/contest/730/problem/B
// 有意思的交互题 1800
void cmp(int i, int j, char &c){
    cout<<"? "<<i<<" "<<j<<endl;
    cin>>c;
}

void slove(){
    int n;
    char c;
    cin>>n;
    int min_d, max_d;
    if(n & 1){
        min_d = max_d = n;
        --n;
    }else{
        cmp(n-1,n,c);
        if(c == '>'){
            min_d = n;
            max_d = n-1;
        }else{
            min_d = n-1;
            max_d = n;
        }
        n -= 2;
    }
    for(int i=1; i<=n; i+=2){
        int a = i,b = i+1;
        cmp(a,b,c);
        if(c == '>') swap(a,b);
        cmp(a,min_d,c);
        if(c == '<')    min_d = a;
        cmp(b,max_d,c);
        if(c == '>')    max_d = b;
    }
    cout<<"! "<<min_d<<" "<<max_d<<endl;
}   
int main()
{
    int t;
    cin>>t;
    while(t--)slove();
}