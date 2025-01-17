/*
 * @lc app=leetcode.cn id=589 lang=cpp
 *
 * [589] N叉树的前序遍历
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    void tranverse(Node* root, vector<int>& result){
        result.push_back(root -> val);
        for(auto child : root -> children){
            tranverse(child, result);
        }
    }
    vector<int> preorder(Node* root) {
        vector<int> result;
        if (root == nullptr)
            return result;
        tranverse(root, result);
        return result;
    }
};
// @lc code=end

