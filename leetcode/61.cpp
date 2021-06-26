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
class Solution {
public:

    int get_size(ListNode *head) {
        int s = 0;
        while(head) {
            ++s;
            head = head->next;
        }
        return s;
    }

    ListNode * reverse_list(ListNode *head) {
        if(head == nullptr) return head;

        ListNode *prev = nullptr, *cur = head, *next;
        while(cur) {
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        return prev;
    }

    ListNode* rotateRight(ListNode* head, int k) {
        if(head == nullptr || head->next == nullptr) return head;
        int n = get_size(head);
        k = k % n;
        if(k == 0) return head;

        ListNode *new_head = reverse_list(head);

        ListNode *k_1th = new_head;
        for(int i = 1; i < k; ++i) {
            k_1th = k_1th->next;
        }

        ListNode *kth = k_1th->next;
        k_1th->next = nullptr;

        ListNode *new_head_tmp = new_head;
        new_head = reverse_list(new_head);
        kth = reverse_list(kth);
        new_head_tmp->next = kth;
        return new_head;
    }
};