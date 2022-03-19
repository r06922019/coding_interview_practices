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
    ListNode *dummy = new ListNode();
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        ListNode *cur = dummy;
        while (l1 || l2)
        {
            if (!l2 || (l1 && l1->val <= l2->val))
            {
                cur->next = l1;
                l1 = l1->next;
                cur = cur->next;
                cur->next = nullptr;
            }
            else
            {
                cur->next = l2;
                l2 = l2->next;
                cur = cur->next;
                cur->next = nullptr;
            }
        }
        ListNode *ret = dummy->next;
        return ret;
    }
};