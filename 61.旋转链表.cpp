/*
 * @lc app=leetcode.cn id=61 lang=cpp
 *
 * [61] 旋转链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(k == 0 || head == nullptr)return head;
        ListNode * back = head, *root = head;
        int n = 1;
        while(back -> next != nullptr){
            n++;
            back = back -> next;
        }
        // cout << n << " " << n-(k%n) << endl;
        back -> next = root;
        for(int i = 0; i < n-(k%n) - 1; i++){
            head = head -> next;
        }
        // cout << head->val<<endl;
        root = head -> next;
        head -> next = nullptr;
        return root; 
    }
};
// @lc code=end

