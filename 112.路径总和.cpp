/*
 * @lc app=leetcode.cn id=112 lang=cpp
 *
 * [112] 路径总和
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
    bool traverse(TreeNode * root, int target){
        if(root == nullptr)return false;
        if(root -> left ==nullptr && root -> right == nullptr && target - root -> val == 0)
            return true;
        else{
            return traverse(root->left, target - (root->val)) || traverse(root->right, target - (root->val));
        }
        
    }
    bool hasPathSum(TreeNode* root, int sum) {
        return traverse(root , sum);
    }
};
// @lc code=end

