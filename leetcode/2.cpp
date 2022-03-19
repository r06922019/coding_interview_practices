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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *cur = dummy;
        int cur_num = 0;
        while (l1 || l2 || cur_num)
        {
            if (l1)
            {
                cur_num += l1->val;
                l1 = l1->next;
            }
            if (l2)
            {
                cur_num += l2->val;
                l2 = l2->next;
            }
            cur->next = new ListNode(cur_num % 10);
            cur_num = cur_num / 10;
            cur = cur->next;
        }
        ListNode *ret = dummy->next;
        dummy->next = nullptr;
        return ret;
    }
};