/*
 * @lc app=leetcode.cn id=101 lang=cpp
 *
 * [101] 对称二叉树
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
    bool solve(TreeNode* r1, TreeNode* r2){
        if (r1 == nullptr && r2 == nullptr)
            return true;
        else if(r1 == nullptr || r2 == nullptr)
            return false;
        if (r1->val != r2 -> val)
            return false;
        return solve(r1->left, r2->right) && solve(r1->right, r2->left);
    }
    bool isSymmetric(TreeNode* root) {
        if(root == nullptr)return true;
        return solve(root -> left, root -> right);
    }
};
// @lc code=end

