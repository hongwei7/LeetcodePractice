/*
 * @lc app=leetcode.cn id=199 lang=cpp
 *
 * [199] 二叉树的右视图
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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        if(root == nullptr)return result;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            for(int i = 0; i < size; i++){
                TreeNode * node = q.front();
                // cout << node->val << endl;
                q.pop();
                if(node->left)q.push(node->left);
                if(node->right)q.push(node->right);
                if(i == size - 1){
                    result.push_back(node->val);
                }
            }
        }
        return result;
    }
};
// @lc code=end

