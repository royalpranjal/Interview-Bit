// https://www.interviewbit.com/problems/reverse-linked-list/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::reverseList(ListNode* A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    struct ListNode* next;
    struct ListNode* prev;
    struct ListNode* curr;
    
    curr = A;
    prev = NULL;
    
    while(curr != NULL){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    
    return prev;
}

// A recursive implementation for the same problem.
// 
// ListNode* Solution::reverseList(ListNode* A) {
//     if(!A || !A->next)return A;
    
//     ListNode* head = A->next;
//     ListNode* p = reverseList(A->next);
//     A->next->next = A;
//     A->next = NULL;
//     return p;
// }
