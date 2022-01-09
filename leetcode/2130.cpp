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
    ListNode *split_list(ListNode *head)
    {
        if (head == nullptr)
            return nullptr;
        ListNode *slow = head, *fast = head, *prev;
        while (fast)
        {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        prev->next = nullptr;
        return slow;
    }

    ListNode *reverse_list(ListNode *head)
    {
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

    int pairSum(ListNode *head1)
    {
        ListNode *head2 = split_list(head1);
        head2 = reverse_list(head2);
        int ans = 0;
        for (; head1 && head2; head1 = head1->next, head2 = head2->next)
            ans = max(head1->val + head2->val, ans);
        return ans;
    }

    // O(n) space
    /*
    int pairSum(ListNode *head)
    {
        vector<int> vec;
        ListNode *cur = head;
        while (cur)
        {
            vec.push_back(cur->val);
            cur = cur->next;
        }

        int ans = 0;
        for (int i = 0, n = vec.size(); i < vec.size(); ++i)
            ans = max(ans, vec[i] + vec[n - 1 - i]);
        return ans;
    }
    */
};