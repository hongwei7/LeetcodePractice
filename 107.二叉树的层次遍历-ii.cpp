/*
 * @lc app=leetcode.cn id=107 lang=cpp
 *
 * [107] 二叉树的层次遍历 II
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void traverse(TreeNode *root, vector<vector<int>> &result, int deep)
    {
        if (root == nullptr)
            return;
        if (result.size() == deep)
            result.push_back(vector<int>(0));
        result[deep].push_back(root->val);
        traverse(root->left, result, deep + 1);
        traverse(root->right, result, deep + 1);
    }
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> result;
        if (root == nullptr)
            return result;
        traverse(root, result, 0);
        reverse(result.begin(), result.end());
        return result;
    }
};
// @lc code=end

