/*
 * @lc app=leetcode.cn id=24 lang=cpp
 *
 * [24] 两两交换链表中的节点
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
class Solution
{
public:
    ListNode *swapPairs(ListNode *head)
    {
        ListNode *now = new ListNode;
        ListNode *root = now;
        now->next = head;
        if (head == nullptr)
            return nullptr;
        if (head->next == nullptr)
            return head;
        while (now->next != nullptr && now->next->next != nullptr)
        {
            ListNode *second = now->next->next, *first = now->next;
            now->next = second;
            first->next = second->next;
            second->next = first;
            now = now->next->next;
        }
        return root->next;
    }
};
// @lc code=end

