#include <bits/stdc++.h>
using namespace std;
// https://codeforces.com/problemset/problem/1535/C
/**
 * 双指针 注意边界 以及精度
*/
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        int n = s.size();
        int t = 0;
        while (t < n && s[t] == '?')    ++t;
        long long i = 0, j = t, pos = t, ans = 0;
        int p = (s[j] - '0') ^ 1; // 上一个字符
        while (j < n){
            if (s[j] == '?'){
                p = p ^ 1;
                ++j;
            }
            else if ((s[j] - '0') ^ p == 0){ // 与上一个字符相同
                ans += (j - i) * (j - i + 1) / 2 - (j - pos - 1) * (j - pos) / 2;
                i = pos + 1;
                pos = j;
                ++j;
            }
            else{ // 相异
                p = p ^ 1;
                pos = j;
                ++j;
            }
        }
        ans += (j - i) * (j - i + 1) / 2;
        cout<<ans<<endl;
    }
}