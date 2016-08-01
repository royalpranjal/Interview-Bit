// https://www.interviewbit.com/problems/subtract/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::subtract(ListNode* A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    if((A == NULL) || (A->next == NULL)){
        return A;
    }
    
    ListNode* curr = A;    
    ListNode* revHead;
    ListNode* mid = A;
    ListNode* origPrev;
    ListNode* temp;
    ListNode* prev = NULL;
    
    while((curr != NULL) && (curr->next != NULL)){
        curr = (curr->next)->next;
        origPrev = mid;
        mid = mid->next;
    }
    
    origPrev->next = NULL;
    
    curr = mid;
    
    while(curr != NULL){
        temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }
    
    revHead = prev;
    
    curr = A;
    temp = revHead;
    
    while(curr != NULL){
        curr->val = (temp->val)-(curr->val);
        curr = curr->next;
        temp = temp->next;
    }
    
    curr = revHead;
    prev = NULL;
    
    while(curr != NULL){
        temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }
    
    origPrev->next = prev;
    
    return A;
    
}
