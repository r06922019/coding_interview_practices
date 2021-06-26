ListNode * reverse_list(ListNode *head) {
    if(head == nullptr) return head;

    ListNode *prev = nullptr, *cur = head, *next;
    while(cur) {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    return prev;
}
