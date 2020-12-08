/*
 * @lc app=leetcode.cn id=230 lang=cpp
 *
 * [230] 二叉搜索树中第K小的元素
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
    bool traverse(TreeNode* root, int& k, int& result){
        if(root -> left){
            if(traverse(root -> left, k, result))return true;
        }
        k --;
        if(k == 0){
            result = root -> val;
            return true;
        }
        if(root -> right){
            if(traverse(root -> right, k, result))return true;
        }
        return false;
    }
    int kthSmallest(TreeNode* root, int k) {
        if(root == nullptr)return -1;
        int result = 0;
        traverse(root, k, result);
        return result;
    }
};
// @lc code=end

