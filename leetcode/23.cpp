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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        auto comp = [](const ListNode *a, const ListNode *b) { return a->val > b->val; };
        priority_queue<ListNode *, vector<ListNode *>, decltype(comp)> pq(comp);
        ListNode *dummy = new ListNode(0);
        for(auto &l : lists) {
            if(l) pq.push(l);
        }
        ListNode *cur = dummy;
        while(pq.size()) {
            auto top = pq.top();
            pq.pop();
            cur->next = top;
            cur = cur->next;
            top = top->next;
            if(top) pq.push(top);
        }
        ListNode *ret = dummy->next;
        delete dummy;
        return ret;
    }
};