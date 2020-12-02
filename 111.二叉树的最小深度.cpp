/*
 * @lc app=leetcode.cn id=111 lang=cpp
 *
 * [111] 二叉树的最小深度
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
class Solution
{
public:
    int solve(TreeNode *root)
    {
        if (root == nullptr)
            return 0;
        if(root -> left == nullptr && root -> right == nullptr) return 1;
        int left = (root->left) ? solve(root->left) : INT_MAX, right = (root->right) ? solve(root->right) : INT_MAX ;
        return min(left, right) + 1;
    }
    int minDepth(TreeNode *root)
    {
        return solve(root);
    }
};
// @lc code=end

