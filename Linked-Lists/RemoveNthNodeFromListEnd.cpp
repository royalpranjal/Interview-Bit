// https://www.interviewbit.com/problems/remove-nth-node-from-list-end/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::removeNthFromEnd(ListNode* A, int B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    ListNode* curr = A;
    ListNode* prev;
    
    if(A == NULL){
        return A;
    }
    
    int size = 0;
    
    while(curr != NULL){
        prev = curr;
        curr = curr->next;
        size++;
    }
    
    if(B == 0){
        B = 1;
    }
    
    int rem = size-B;
    
    if(rem <= 0){
        return A->next;
    }
    
    curr = A;
    
    while(rem > 0){
        prev = curr;
        curr = curr->next;
        rem--;
    }
    
    prev->next = curr->next;
    
    return A;
    
}
