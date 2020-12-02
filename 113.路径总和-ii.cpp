/*
 * @lc app=leetcode.cn id=113 lang=cpp
 *
 * [113] 路径总和 II
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
    void traverse(TreeNode *root, int target, vector<vector<int>>& result, vector<int>& path)
    {
        if (root == nullptr)
            return;
        path.push_back(root -> val);
        if (root->left == nullptr && root->right == nullptr && target - root->val == 0){
            result.push_back(path);
        }
        else
        {
            traverse(root->left, target - (root->val), result, path);
            traverse(root->right, target - (root->val), result, path); 
        }
        path.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> result;
        vector<int> path;
        traverse(root, sum, result, path);
        return result;
    }
};
// @lc code=end

