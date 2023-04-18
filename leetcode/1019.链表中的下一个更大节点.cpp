/*
 * @lc app=leetcode.cn id=1019 lang=cpp
 *
 * [1019] 链表中的下一个更大节点
 */

#include<bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        map<ListNode*, int> m;
        vector<ListNode *> stack;
        vector<int> ans;
        ListNode *root = head;
        while (root != nullptr)
        {
            while(!stack.empty() && root->val > stack.back()->val){
                m[stack.back()] = root->val;
                stack.pop_back();
            }
            stack.push_back(root);
            root = root->next;
        }
        while (!stack.empty())
        {
            m[stack.back()] = 0;
            stack.pop_back();
        }
        root = head;
        while (root != nullptr)
        {
            ans.push_back(m[root]);
            root = root->next;
        }
        return ans;
    }
};
// @lc code=end

