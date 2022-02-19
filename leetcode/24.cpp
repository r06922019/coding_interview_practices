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
        ListNode *dummy = new ListNode(0, head);
        ListNode *cur = dummy;
        while (cur && cur->next && cur->next->next)
        {
            auto next_next_next = cur->next->next->next;
            auto next_next = cur->next->next;
            auto next = cur->next;
            cur->next = next_next;
            next_next->next = next;
            next->next = next_next_next;
            cur = next;
        }
        ListNode *ret = dummy->next;
        delete (dummy);
        return ret;
    }
};