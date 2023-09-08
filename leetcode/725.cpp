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
    int get_size(ListNode *head)
    {
        int s = 0;
        while (head)
        {
            head = head->next;
            ++s;
        }
        return s;
    }

    vector<ListNode *> splitListToParts(ListNode *head, int k)
    {
        int n = get_size(head);
        int part_size = n / k;
        vector<int> sizes(k, part_size);
        for (int i = 0, mod = n % k; i < mod; ++i)
        {
            ++sizes[i];
        }
        vector<ListNode *> ans;
        for (int i = 0; i < k; ++i)
        {
            ans.push_back(head);
            for (int j = 1; j < sizes[i] && head; ++j)
            {
                head = head->next;
            }
            if (head)
            {
                ListNode *tmp = head->next;
                head->next = nullptr;
                head = tmp;
            }
        }
        return ans;
    }
};