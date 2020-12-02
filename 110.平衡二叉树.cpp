/*
 * @lc app=leetcode.cn id=110 lang=cpp
 *
 * [110] 平衡二叉树
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
    bool tranverse(TreeNode* root, int& height){
        int left = 0, right = 0;
        if(root -> left != nullptr){
            left ++;
            if(!tranverse(root -> left, left)){
                return false;
            }
        }
        if (root->right != nullptr)
        {
            right ++;
            if (!tranverse(root->right, right))
            {
                return false;
            }
        } 
        height =  height + max(left, right);
        if(abs(left - right) > 1)return false;
        else return true;
    }
    bool isBalanced(TreeNode* root) {
        if(root == nullptr)return true;
        int height;
        return tranverse(root, height);
    }
};
// @lc code=end

