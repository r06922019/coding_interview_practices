class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        // iterative
        ListNode *prev = nullptr, *cur = head;
        while(cur) {
            ListNode *next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        return prev;

        // recursive
        if(head == nullptr || head->next == nullptr) return head;
        ListNode *next = head->next;
        ListNode *new_head = reverseList(head->next);
        next->next = head;
        head->next = nullptr;
        return new_head;
    }
};