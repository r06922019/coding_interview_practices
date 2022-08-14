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

    ListNode *reverseList(ListNode *head)
    {
        if (head == nullptr)
            return nullptr;
        ListNode *prev = nullptr, *cur = head;
        while (cur)
        {
            ListNode *next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        return prev;
    }

    ListNode *reverseBetween(ListNode *head, int left, int right)
    {
        dummy->next = head;
        ListNode *rev_start = dummy, *rev_start_prev = dummy;
        for (int i = 0; i < left; ++i)
        {
            rev_start_prev = rev_start;
            rev_start = rev_start->next;
        }

        ListNode *rev_end = dummy, *rev_end_next;
        for (int i = 0; i < right; ++i)
            rev_end = rev_end->next;
        rev_end_next = rev_end->next;
        rev_end->next = nullptr;

        rev_start_prev->next = reverseList(rev_start);
        rev_start->next = rev_end_next;
        return dummy->next;
    }
};