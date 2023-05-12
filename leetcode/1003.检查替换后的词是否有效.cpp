/*
 * @lc app=leetcode.cn id=1003 lang=cpp
 *
 * [1003] 检查替换后的词是否有效
 */
#include<bits/stdc++.h>
using namespace std;

// @lc code=start
// 简单的栈操作
class Solution {
public:
    bool isValid(string s) {
        vector<char> st;
        st.push_back('*');
        st.push_back('*');
        for(auto & c : s){
            if(c == 'c'){
                int size = st.size();
                if(st[size-1] == 'b' and st[size-2] == 'a'){
                    st.pop_back();
                    st.pop_back();
                }else{
                    return false;
                }
            }else{
                st.push_back(c);
            }
        }
        return st.size() == 2;

    }
};
// @lc code=end

