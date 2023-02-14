class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        
    if(head==NULL)
        return NULL;
    
    //reverse 1st k nodes
    ListNode* forward=NULL;
    ListNode* prev=NULL;
    ListNode* curr=head;
    int cnt=0;
    
    ListNode* cursor = head;
    for(int i = 0; i < k; i++){
         if(cursor == nullptr) 
             return head;
         cursor = cursor->next;
    }
    while(curr!=NULL && cnt<k ){
        forward=curr->next;
        curr->next=prev;
        prev=curr;
        curr=forward;
        cnt++;
    }
    
    head->next=reverseKGroup(forward,k);
    return prev;
    }
};
