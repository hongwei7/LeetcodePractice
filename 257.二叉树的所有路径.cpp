/*
 * @lc app=leetcode.cn id=257 lang=cpp
 *
 * [257] 二叉树的所有路径
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
    void traverse(TreeNode* root, vector<string>& result, string now){
        if(root == nullptr)return;
        now = now + "->" + to_string(root->val);
        traverse(root -> left, result, now);
        traverse(root -> right, result, now);
        if(root -> left == nullptr && root -> right == nullptr){
            result.push_back(now.substr(2, now.size() - 2));
        }
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        if(root == nullptr)return result;
        string now = "";
        traverse(root, result, now);
        return result;
    }
};
// @lc code=end

