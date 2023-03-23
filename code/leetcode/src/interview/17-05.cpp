#include"../../header/leetcode.h"
//https://leetcode.cn/problems/find-longest-subarray-lcci/
//面试题 17.05.字母与数字
//前缀和  哈希表
class Solution {
public:
    vector<string> findLongestSubarray(vector<string>& array) {
        unordered_map<int, int> last;
        vector<string> ans;
        int n = array.size(), len = 0, pos = 0;
        int pre = 0;
        last[0] = -1;
        for(int i=0; i<n; ++i){
            string &s = array[i];
            if(s[0]>= '0' && s[0] <= '9')++pre;
            else --pre;
            if(last.find(pre) == last.end()){
                last[pre] = i;
            }
            auto it = last.find(pre);
            if(it != last.end()){
                if(i - it->second > len){
                    len = i - it->second;
                    pos = it->second;
                }
            }
        }
        for(int i=1; i<=len; ++i){
            ans.push_back(array[i+pos]);
        }
        return ans;
    }
};
