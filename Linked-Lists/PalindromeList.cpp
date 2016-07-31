// https://www.interviewbit.com/problems/palindrome-list/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
int Solution::lPalin(ListNode* A) {
    
    ListNode* curr = A;
    ListNode* mid = A;
    ListNode* prev;
    ListNode* newCurr;
    ListNode* newTemp;
    ListNode* newPrev;
    
    if(curr == NULL){
        return 1;
    }
    if(curr->next == NULL){
        return 1;
    }
        
    while((curr != NULL) && (curr->next != NULL)){
        curr = (curr->next)->next;
        prev = mid;
        mid = mid->next;
    }
    
    prev->next = NULL;
    
    newCurr = mid;
    while(newCurr != NULL){
        newTemp = newCurr->next;
        if(newCurr == mid){
            newCurr->next = NULL;
            newPrev = newCurr;
            newCurr = newTemp;
        }
        else{
            newCurr->next = newPrev;
            newPrev = newCurr;
            newCurr = newTemp;
        }
    }
    
    curr = A;
    
    while((newPrev != NULL) && (curr != NULL)){
        if(newPrev->val != curr->val){
            return 0;
        }
        newPrev = newPrev->next;
        curr = curr->next;
    }
    
    return 1;
    
}
