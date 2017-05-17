/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::reverseList(ListNode* A, int B) {
    if(!A || B == 1 || B == 0){
        return A;
    }
    
    ListNode* head = NULL, *curr = A, *prev = NULL, *tempHead = NULL;
    
    for(int i = 0; i < B; i++){
        ListNode *temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
        
        if(tempHead == NULL){
            tempHead = prev;
        }
    }
    
    head = prev;

    prev = NULL;
    
    while(curr){
        ListNode* t = NULL;
        
        for(int i = 0; i < B; i++){
            ListNode *temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
            
            if(!t){
                t = prev;
            }
        }
        
        tempHead->next = prev;
        tempHead = t;
    }
    
    if(tempHead){
        tempHead->next = NULL;
    }
    
    return head;
}
