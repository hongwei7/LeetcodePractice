/*
 * @lc app=leetcode.cn id=897 lang=cpp
 *
 * [897] 递增顺序查找树
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
    void traverse(TreeNode* root, TreeNode*& now){
        if(root == nullptr) return;
        traverse(root -> left, now);
        now -> right = new TreeNode(root -> val);
        now = now -> right;
        traverse(root -> right, now);
    }
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode* nroot = new TreeNode, *now = nroot;
        traverse(root, now);
        return nroot -> right;
    }
};
// @lc code=end

