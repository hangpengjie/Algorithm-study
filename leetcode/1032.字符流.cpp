/*
 * @lc app=leetcode.cn id=1032 lang=cpp
 *
 * [1032] 字符流
 * 
 */
/**
 * 字典树，从后向前建树
*/
#include"../code/leetcode/header/leetcode.h"
// @lc code=start
struct Tire
{
    Tire* children[26] = {};
    bool isEnd = false;
};
class StreamChecker {
private:
    Tire *root;
    vector<char> str;
public:
    StreamChecker(vector<string>& words) {
        root = new Tire;
        for(const auto &word : words){
            Tire *node = root;
            for(auto c = word.rbegin(); c != word.rend(); ++c){
                if(node->children[*c - 'a'] == nullptr){
                    node->children[*c - 'a'] = new Tire;
                }
                node = node->children[*c - 'a'];
            }
            node->isEnd = true;
        }
    }
    
    bool query(char letter) {
        str.push_back(letter);
        Tire *node = root;
        for(auto c = str.rbegin(); c != str.rend(); ++c){
            node = node->children[*c - 'a'];
            if(node == nullptr) return false;
            if(node->isEnd) return true;
        }
        return false;
    }
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */
// @lc code=end

