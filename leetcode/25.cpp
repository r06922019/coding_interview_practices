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

    ListNode *reverse_list(ListNode *head) {
        ListNode *cur = head, *prev = nullptr;
        while(cur) {
            ListNode *next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        return prev;
    }

    ListNode *reverseKGroup(ListNode *head, int k) {
        ListNode *dummy = new ListNode(0, head);
        ListNode *cur = dummy;
        while(cur && cur->next) {
            // check if we have a sublist with length k
            ListNode *front = cur;
            int len = 0;
            while(len < k && front->next) {
                front = front->next;
                ++len;
            }
            if(len < k) {
                break;
            }

            ListNode *next = front->next;
            front->next = nullptr;
            ListNode *old_cur_next = cur->next;
            cur->next = reverse_list(cur->next);
            old_cur_next->next = next;
            cur = old_cur_next;
        }
        ListNode* ret = dummy->next;
        delete dummy;
        return ret;
    }
};