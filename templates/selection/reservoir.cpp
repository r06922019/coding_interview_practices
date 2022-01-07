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
    ListNode* head = nullptr;
    Solution(ListNode* head_) {
        head = head_;
    }
    
    int getRandom() {
        ListNode* cur = head, *selected = nullptr;
        for(int i = 1; cur != nullptr; ++i, cur = cur->next) {
            float p = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
            if(p < (1/(double)i)) {
                selected = cur;
            }
        }
        return selected->val;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */