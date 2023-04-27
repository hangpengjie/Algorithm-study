/*
 * @lc app=leetcode.cn id=1163 lang=cpp
 *
 * [1163] 按字典序排在最后的子串
 */
#include<bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    string lastSubstring(string s) {
        
        char c = 'a' - 1;   // 记录最大字符
        int ans = -1;       // 最终一定是字符串s的后缀，ans表示字典序最大子串的开始（即要求的答案）
        // 注意：从后向前遍历更加好算也更容易证明
        // 贪心算法
        for (int i = s.size()-1; i >= 0; --i) {
            if(s[i] > c){
                ans = i;
                c = s[i];
            }else if(s[i] == c){
                int p = 1;
                bool cge = true;
                // ans记录下来的一定是从ans开始的最大的子串
                // 更新结果的时候只需要比较待比较的字符串开始位置 i 到 ans 这一段字符串即可，因为ans开头的一定是从ans开始的最大的子串
                while (ans + p < s.size() && i + p < ans){
                    if(s[ans + p] > s[i + p]){
                        cge = false;
                        break;
                    }
                    if(s[ans + p] < s[i + p]){
                        break;
                    }
                    p++;
                }
                if(cge) ans = i;
            }
        }

        return s.substr(ans);
    }
};
// @lc code=end

