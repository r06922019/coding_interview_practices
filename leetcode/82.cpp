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
    ListNode *dummy = new ListNode(0);
    ListNode *deleteDuplicates(ListNode *head)
    {
        ListNode *new_head = dummy, *cur = head;
        while (cur)
        {
            ListNode *next = cur->next;
            if (next == nullptr || cur->val != next->val)
            {
                cur->next = nullptr;
                new_head->next = cur;
                new_head = new_head->next;
                cur = next;
            }
            else
            {
                int val = cur->val;
                while (cur && cur->val == val)
                {
                    cur = cur->next;
                }
            }
        }
        ListNode *ret = dummy->next;
        dummy->next = nullptr;
        return ret;
    }
};