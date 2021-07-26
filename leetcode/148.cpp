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
    ListNode* sortList(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return head;
        ListNode *dummy = new ListNode(0, head);
        ListNode *slow = dummy, *fast = dummy;
        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *l1 = dummy->next;
        ListNode *l2 = slow->next;
        slow->next = nullptr;

        l1 = sortList(l1);
        l2 = sortList(l2);
        ListNode *cur = dummy;
        while(l1 || l2) {
            if(l2 == nullptr || (l1 && l1->val <= l2->val)) {
                cur->next = l1;
                l1 = l1->next;
            }
            else {
                cur->next = l2;
                l2 = l2->next;
            }
            cur = cur->next;
        }
        cur->next = nullptr;
        ListNode *ret = dummy->next;
        delete dummy;
        return ret;
    }
};