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
    ListNode* oddEvenList(ListNode* head) {
        if(head == nullptr || head->next == nullptr || head->next->next == nullptr)
            return head;

        ListNode *odd_head = head, *odd_cur = head;
        ListNode *even_head = head->next, *even_cur = head->next;
        ListNode *cur = head->next->next;
        int index = 3;
        while(cur) {
            if(index % 2 == 1) {
                odd_cur->next = cur;
                odd_cur = odd_cur->next;
            }
            else {
                even_cur->next = cur;
                even_cur = even_cur->next;
            }
            cur = cur->next;
            ++index;
        }
        odd_cur->next = even_head;
        even_cur->next = nullptr;
        return odd_head;
    }
};