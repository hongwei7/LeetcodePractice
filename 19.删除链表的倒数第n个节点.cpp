/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第N个节点
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
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *back = head, *front = head;
        if (head->next == nullptr)
            return nullptr;
        for (int i = 0; i < n; i++)
            back = back->next;
        if (back == nullptr)
        {
            head = head->next;
            return head;
        }
        while (back->next != nullptr)
        {
            front = front->next;
            back = back->next;
        }
        front->next = front->next->next;
        return head;
    }
};
// @lc code=end

