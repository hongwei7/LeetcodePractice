/*
 * @lc app=leetcode.cn id=654 lang=cpp
 *
 * [654] 最大二叉树
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
    TreeNode* traverse(vector<int>& nums, int start, int end){
        if(start > end)return nullptr;
        int maxNum = nums[start], maxi = start;
        for(int i = start + 1; i <= end; i++){
            if(maxNum < nums[i]){
                maxi = i;
                maxNum = nums[i];
            }
        }
        return new TreeNode(maxNum, traverse(nums, start, maxi - 1), traverse(nums, maxi + 1, end));
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return traverse(nums, 0, nums.size() - 1);
    }
};
// @lc code=end

