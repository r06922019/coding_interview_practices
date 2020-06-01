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
        // https://stackoverflow.com/questions/5807735/c-priority-queue-with-lambda-comparator-error
        auto greater_ListNodePtr = []( ListNode * a, ListNode * b ) { return a->val > b->val; };
        priority_queue<ListNode *, vector<ListNode *>, decltype(greater_ListNodePtr)> pq(greater_ListNodePtr);

        ListNode *dummy = new ListNode(0);
        ListNode *cur = dummy;

        // fill in pq
        for(ListNode *l : lists) {
            if(l) pq.push(l);
        }

        // pop from pq
        while(pq.size()) {
            ListNode *node = pq.top();
            pq.pop();

            ListNode *next_node_in_list = node->next;
            node->next = nullptr;
            if(next_node_in_list)
                pq.push(next_node_in_list);

            cur->next = node;
            cur = cur->next;
        }
        return dummy->next;
    }
};