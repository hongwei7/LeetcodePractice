/*
 * @lc app=leetcode.cn id=501 lang=cpp
 *
 * [501] 二叉搜索树中的众数
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
    void travrse(TreeNode* root, map<int, int>& nmap){
        if(root == nullptr)return;
        nmap[root -> val]++;
        travrse(root -> left, nmap);
        travrse(root -> right, nmap);
    }
    vector<int> findMode(TreeNode* root) {
        vector<int> result;
        if(!root) return result;
        map<int, int> nmap;
        travrse(root, nmap);
        int maxn, maxv = 0;
        for(auto iter = nmap.begin(); iter != nmap.end(); iter++){
            maxv = max(maxv, iter->second);
        }
        for(auto iter = nmap.begin(); iter != nmap.end(); iter++){
            if(iter->second == maxv)result.push_back(iter->first);
        }
        return result;
    }
};
// @lc code=end

