/*
 * @lc app=leetcode.cn id=94 lang=cpp
 *
 * [94] 二叉树的中序遍历
 */

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
    void solve(vector<int>& result, TreeNode* root){
        if(root == nullptr)return;
        solve(result, root->left);
        result.push_back(root -> val);
        solve(result, root -> right);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        solve(result, root);
        return result;
    }
};
// @lc code=end

