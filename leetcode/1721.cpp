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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode *node_a = head, *fake_node_b = head, *node_b = head;
        for(int i = 1; i < k; ++i) {
            node_a = node_a->next;
            fake_node_b = fake_node_b->next;
        }
        while(fake_node_b->next) {
            fake_node_b = fake_node_b->next;
            node_b = node_b->next;
        }
        swap(node_a->val, node_b->val);
        return head;
    }
};