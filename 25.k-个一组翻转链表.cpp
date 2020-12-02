// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem25.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=25 lang=cpp
 *
 * [25] K 个一组翻转链表
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
    pair<ListNode*, ListNode*> reverseList(ListNode* head, ListNode * tail){
        ListNode *now = head, *back = head->next, *temp, *end = tail->next;
        while(back != end){
            temp = back -> next;
            back -> next = now;
            now = back;
            back = temp;
        }
        head->next = nullptr;
        return {tail, head};
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* root = new ListNode(-1, head);
        ListNode* front = root, *back;
        ListNode* tail = head;
        bool finish = 0;
        while (tail != nullptr && !finish)
        {
            for (int i = 0; i < k - 1 ; i++)
            {
                if (tail->next == nullptr){
                    finish = 1;
                    break;
                }
                tail = tail->next;
            }
            if(!finish){
                back = tail->next;
                pair<ListNode *, ListNode *> result = reverseList(head, tail);
                front->next = result.first;
                front = result.second;
                result.second->next = back;
                head = back;
                tail = head;
            }
        }
        return root -> next;
    }   
};
// @lc code=end

