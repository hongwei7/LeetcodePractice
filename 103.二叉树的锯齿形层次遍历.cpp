/*
 * @lc app=leetcode.cn id=103 lang=cpp
 *
 * [103] 二叉树的锯齿形层次遍历
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
        if (root != nullptr){
            if (deep % 2 == 0){
                result[deep].push_back(root->val);
            }
            else
            {
                result[deep].insert(result[deep].begin(), root->val);
            }
        }
        traverse(root->left, result, deep + 1);
        traverse(root->right, result, deep + 1);
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (root == nullptr)
            return result;
        traverse(root, result, 0);
        return result;
    }
};
// @lc code=end

