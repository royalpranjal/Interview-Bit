// https://www.interviewbit.com/problems/swap-list-nodes-in-pairs/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::swapPairs(ListNode* A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    if(A == NULL){
        return A;
    }
    
    ListNode* curr = A;
    ListNode* ahead = curr->next;
    if(ahead == NULL){
        return A;
    }
    ListNode* ans = ahead;
    ListNode* temp;
    ListNode* prev = NULL;
    
    while((curr != NULL) && (ahead != NULL)){
        temp = ahead->next;
        curr->next = temp;
        ahead->next = curr;
        if(prev != NULL){
            prev->next = ahead;
        }
        prev = curr;
        curr = curr->next;
        if(curr != NULL){
            ahead = curr->next;    
        }
    }
    
    return ans;
}
