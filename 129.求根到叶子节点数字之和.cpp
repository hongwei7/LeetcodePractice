// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem129.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=129 lang=cpp
 *
 * [129] 求根到叶子节点数字之和
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
    void traverse(TreeNode* root, int& sum, int& q){
        if(root == nullptr){
            return;
        }
        q = 10 * q + root->val;
        if (root->left == nullptr && root->right == nullptr)
        {
            sum += q;
        }
        traverse(root->left, sum, q);
        traverse(root->right, sum, q);
        q = (q - root->val) / 10;
    }
    int sumNumbers(TreeNode* root) {
        int sum = 0, q = 0;
        traverse(root, sum, q);
        return sum;
    }
};
// @lc code=end

