/*
 * @lc app=leetcode.cn id=1026 lang=cpp
 *
 * [1026] 节点与其祖先之间的最大差值
 */
#include<bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
   TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int ans = 0;
    pair<int,int> dfs(TreeNode *root){
        pair<int,int> ret{root->val,root->val};
        if(root->left != nullptr){
            auto l = dfs(root->left);
            ans = max(ans,max(abs(root->val - l.first),abs(root->val - l.second)));
            ret.first = min(ret.first,l.first);
            ret.second = max(ret.second,l.second);
        }
        if(root->right != nullptr){
            auto l = dfs(root->right);
            ans = max(ans,max(abs(root->val - l.first),abs(root->val - l.second)));
            ret.first = min(ret.first,l.first);
            ret.second = max(ret.second,l.second);
        }
        return ret;
    }
    int maxAncestorDiff(TreeNode* root) {
        dfs(root);
        return ans;
    }
};
// @lc code=end

