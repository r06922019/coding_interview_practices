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
    ListNode *dummy1 = new ListNode(0);
    ListNode *dummy2 = new ListNode(0);

    ListNode *partition(ListNode *head, int x)
    {
        ListNode *cur1 = dummy1, *cur2 = dummy2, *cur = head;
        while (cur)
        {
            if (cur->val >= x)
            {
                cur2->next = cur;
                cur2 = cur2->next;
            }
            else
            {
                cur1->next = cur;
                cur1 = cur1->next;
            }
            cur = cur->next;
        }
        cur1->next = dummy2->next;
        cur2->next = nullptr;
        return dummy1->next;
    }
};