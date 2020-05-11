struct ListNode* reverseList(struct ListNode* head){
    struct ListNode* p=NULL,* temp=NULL;
    while(head){
        temp=head->next;
        head->next=p;
        p=head;
        head=temp;
    }
    return p;
}
