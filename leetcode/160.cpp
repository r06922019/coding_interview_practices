/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        bool curA_restarted = false, curB_restarted = false;
        ListNode *curA = headA, *curB = headB;
        while(curA || curB) {
            if(curA == nullptr) {
                if(!curA_restarted) {
                    curA_restarted = true;
                    curA = headB;
                }
                else {
                    break;
                }
            }
            if(curB == nullptr) {
                if(!curB_restarted) {
                    curB_restarted = true;
                    curB = headA;
                }
                else {
                    break;
                }
            }
            if(curA == curB) return curA;
            curA = curA->next;
            curB = curB->next;
        }
        return nullptr;
    }
};