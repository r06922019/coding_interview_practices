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

    bool list_equal(ListNode *a, ListNode *b)
    {
        if (a == nullptr && b == nullptr)
            return true;
        else if (a == nullptr || b == nullptr)
            return false;
        while (a || b)
        {
            if (a == nullptr || b == nullptr)
                return false;
            if (a->val != b->val)
                return false;
            a = a->next;
            b = b->next;
        }
        return true;
    }

    ListNode *reverse_list(ListNode *head)
    {
        if (head == nullptr)
            return nullptr;
        ListNode *cur = head, *prev = nullptr;
        while (cur)
        {
            ListNode *next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        return prev;
    }

    ListNode *copy_list(ListNode *head)
    {
        ListNode *cur = dummy;
        while (head)
        {
            cur->next = new ListNode(head->val);
            cur = cur->next;
            head = head->next;
        }
        return dummy->next;
    }

    bool isPalindrome(ListNode *head)
    {
        ListNode *new_head = copy_list(head);
        new_head = reverse_list(new_head);
        return list_equal(head, new_head);
    }
};