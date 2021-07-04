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

    ListNode *reverseList(ListNode *head) {
        ListNode *cur = head, *prev = nullptr;
        while(cur) {
            ListNode *next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        return prev;
    }

    ListNode *splitList(ListNode *head) {
        ListNode *slow = head, *fast = head, *prev = nullptr;
        while(fast && fast->next) {
            fast = fast->next->next;
            prev = slow;
            slow = slow->next;
        }
        ListNode *head1 = prev->next;
        prev->next = nullptr;
        return head1;
    }

    bool isPalindrome(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return true;

        ListNode *head1 = splitList(head);
        head1 = reverseList(head1);
        while(head && head1) {
            if(head->val != head1->val) return false;
            head = head->next;
            head1 = head1->next;
        }
        return true;
    }
};