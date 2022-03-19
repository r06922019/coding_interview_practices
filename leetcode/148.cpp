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

    ListNode *merge_list(ListNode *a, ListNode *b)
    {
        dummy->next = nullptr;
        ListNode *cur = dummy;
        while (a || b)
        {
            if (b == nullptr || (a && a->val <= b->val))
            {
                ListNode *next = a->next;
                a->next = nullptr;
                cur->next = a;
                cur = cur->next;
                a = next;
            }
            else
            {
                ListNode *next = b->next;
                b->next = nullptr;
                cur->next = b;
                cur = cur->next;
                b = next;
            }
        }
        return dummy->next;
    }

    ListNode *get_middle(ListNode *head)
    {
        ListNode *slow = head, *slow_prev = nullptr, *fast = head;
        while (fast && fast->next)
        {
            slow_prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        slow_prev->next = nullptr;
        return slow;
    }

    ListNode *sortList(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
            return head;
        ListNode *mid = get_middle(head);
        mid = sortList(mid);
        head = sortList(head);
        return merge_list(head, mid);
    }
};