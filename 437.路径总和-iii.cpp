// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem437.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=437 lang=cpp
 *
 * [437] 路径总和 III
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
    void traverseC(TreeNode* root, int sum, int& target, int& pathsum){
        if(root == nullptr)return;
        sum = sum + root -> val;
        if(sum == target)pathsum ++;
        traverseC(root->left, sum, target, pathsum);
        traverseC(root->right, sum, target, pathsum);
    }
    void traverse(TreeNode* root, int target, int& pathsum){
        if(root == nullptr)return;
        traverseC(root, 0, target, pathsum);
        traverse(root->left, target, pathsum);
        traverse(root->right, target, pathsum);
    }
    int pathSum(TreeNode* root, int target) {
        int pathsum = 0;
        traverse(root, target, pathsum);
        return pathsum;
    }
};
// @lc code=end

