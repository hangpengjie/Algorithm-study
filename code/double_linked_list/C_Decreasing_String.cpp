#include<bits/stdc++.h>
# define MULTI
//# define INIT
using namespace std;
#include<math.h>
# define endl '\n'
# define space ' '
# define LL long long
# define PII pair<int, int>
// by hangpengjie

/**
 * 题目: C. Decreasing String
 * 链接: https://codeforces.com/contest/1886/problem/C
 * 省流: 双链表非常规解法，正解是单调栈！！！  大佬的代码: https://codeforces.com/contest/1886/submission/227350420
 * 
 * 双链表解法: 记录每个字母s[i]对应的l[i] 和 r[i] 如果s[i] > s[r[i]] 说明在这一轮中可以将s[i]删掉同时记得更新l[r[i]] 以及 r[l[i]]
 * 代码: https://codeforces.com/contest/1886/submission/228567235
*/
void slove(){
    string s;
    LL pos, n;
    cin >> s >> pos;
    n = s.size();
    s = '0' + s;
    vector<int> l(n+1, 0),r(n+1, 0);
    for(int i=1; i<=n; ++i){
        l[i] = i-1;
        r[i] = i+1;
    }
    r[0] = 1;
    r[n] = 0;
    int d = n;
    int i = 1;
    while(pos > d){
        while(s[i] <= s[r[i]]) i = r[i];    // 这里一定不能写成 i++ 把i想象成链表处理！！！
        r[l[i]] = r[i];
        l[r[i]] = l[i];
        i = l[i];
        pos -= d;
        d--;
    }
    int c = 0;
    while(pos > 0){
        c = r[c];
        pos--;
    }
    cout << s[c] ;
    
}

# ifdef INIT
void init(){
  
}
# endif

int main()
{
    # ifdef INIT
    init();
    # endif

    int cas = 1;
    # ifdef MULTI
    cin >> cas;
    # endif

    while (cas--){
        slove();
    }
    
}


