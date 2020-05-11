bool hasCycle(struct ListNode *head) {
    if(NULL==head) return false;
    struct ListNode *fast=head->next,*slow=head;
    while(fast!=slow){
        if(!fast||!fast->next){
            return false;
        }
        slow=slow->next;
        fast=fast->next->next;
    }
    return true;
}
