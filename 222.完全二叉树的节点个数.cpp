/*
 * @lc app=leetcode.cn id=222 lang=cpp
 *
 * [222] 完全二叉树的节点个数
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
    int countNodes(TreeNode* root) {
        if(root == nullptr)return 0;
        TreeNode* now = root;
        int hLeft = 0, hRight = 0;
        while(now != nullptr){
            now = now -> left;
            hLeft ++;
        }
        now = root;
        while(now != nullptr){
            now = now -> right;
            hRight ++;
        }
        cout << hLeft;
        if(hLeft == hRight)return pow(2, hLeft) - 1;
        else return countNodes(root->left) + countNodes(root->right) + 1;
    }
};
// @lc code=end

