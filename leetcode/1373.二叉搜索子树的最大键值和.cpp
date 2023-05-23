/*
 * @lc app=leetcode.cn id=1373 lang=cpp
 *
 * [1373] 二叉搜索子树的最大键值和
 */
#include<bits/stdc++.h>
using namespace std;
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
// 后序遍历过程记录并更新信息
// 当前树结构的最小值、最大值、键值和、是否是二叉搜索树
struct Z{int mn,mx,sum,ok;};

class Solution {
public:
    int ans = 0;
    Z dfs(TreeNode* root){
        if(root == nullptr) return {INT32_MAX, INT32_MIN, 0, 1};
        Z left = dfs(root->left);
        Z right = dfs(root->right);
        Z res = {root->val, root->val, root->val, 0};
        if(left.ok && right.ok && root->val > left.mx && root->val < right.mn){
            res.mn = min(res.mn, min(left.mn,right.mn));
            res.mx = max(res.mx, max(left.mx, right.mx));
            res.sum += left.sum + right.sum;
            res.ok = 1;
            ans = max(ans, res.sum);
        }
        return res;
    }
    int maxSumBST(TreeNode* root) {
        dfs(root);
        return ans;
    }
};
// @lc code=end

