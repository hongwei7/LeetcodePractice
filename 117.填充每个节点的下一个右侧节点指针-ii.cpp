// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem117.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=117 lang=cpp
 *
 * [117] 填充每个节点的下一个右侧节点指针 II
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution
{
public:

    Node *connect(Node *root)
    {
        if(root == nullptr)return nullptr;
        queue<Node*> q;
        q.push(root);
        Node* pre;
        while(!q.empty()){
            int size = q.size();
            Node* node = root;
            for(int i = 0; i < size; i++){
                if(i == 0){
                    pre = q.front();
                    q.pop();
                    node = pre;
                }
                else{
                    node = q.front();
                    q.pop();
                    pre->next = node;
                    pre = node;
                }
                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }
            pre -> next = nullptr;
        }
        
        return root;
    }
};
// @lc code=end

