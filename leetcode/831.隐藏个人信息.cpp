/*
 * @lc app=leetcode.cn id=831 lang=cpp
 *
 * [831] 隐藏个人信息
 */
#include<bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<string> country = {"", "+*-", "+**-", "+***-"};
    string maskPII(string s) {
        string res;
        int at = s.find('@');
        if(at != string::npos){
            transform(s.begin(),s.end(),s.begin(),::tolower);
            return s.substr(0,1)+"*****"+s.substr(at-1);
        }
        s = regex_replace(s,regex("[^0-9]"),"");
        return country[s.size() - 10] + "***-***-"+s.substr(s.size() - 4);
    }
};
// @lc code=end

