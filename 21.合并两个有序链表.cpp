/*
 * @lc app=leetcode.cn id=21 lang=cpp
 *
 * [21] 合并两个有序链表
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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        ListNode *head = new ListNode, *now = head;
        if (!(l1 != nullptr || l2 != nullptr))
            return nullptr;
        while (1)
        {
            int l1v = (l1 == nullptr) ? l2->val : l1->val;
            int l2v = (l2 == nullptr) ? l1->val : l2->val;
            if (l1v <= l2v && l1 != nullptr)
            {
                now->val = (l1v);
                l1 = l1->next;
            }
            else
            {
                now->val = (l2v);
                l2 = l2->next;
            }
            if (!(l1 != nullptr || l2 != nullptr))
                return head;
            ListNode *temp = new ListNode;
            now->next = temp;
            now = now->next;
        }
        return head;
    }
};
// @lc code=end

