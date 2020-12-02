/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        int in = 0, add, val1, val2;
        ListNode *root = new ListNode(0);
        root->next = NULL;
        ListNode *p = root;
        while (l1 != NULL || l2 != NULL)
        {
            if (l1 != NULL)
                val1 = l1->val;
            else
                val1 = 0;
            if (l2 != NULL)
                val2 = l2->val;
            else
                val2 = 0;
            add = val1 + val2 + in;
            p->val = add % 10;
            p->next = new ListNode(0);
            if (l1 != NULL)
                l1 = l1->next;
            if (l2 != NULL)
                l2 = l2->next;
            if (l1 != NULL || l2 != NULL)
                p = p->next;
            in = add / 10;
        }
        if (in)
            p->next = new ListNode(1);
        else
            p->next = NULL;
        return root;
    }
};
// @lc code=end

