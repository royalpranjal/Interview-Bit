// https://www.interviewbit.com/problems/reverse-link-list-recursion/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* reverseLinkedList(ListNode* curr, ListNode* prev){
    if(curr == NULL){
        return prev;
    }
    ListNode* temp = curr->next;
    curr->next = prev;
    prev = curr;
    curr = temp;
    return reverseLinkedList(curr, prev);
} 
 
ListNode* Solution::reverseList(ListNode* A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    if(A == NULL){
        return A;
    }
    
    return reverseLinkedList(A, NULL);
}
