// https://www.interviewbit.com/problems/remove-duplicates-from-sorted-list/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::deleteDuplicates(ListNode* A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    if(A == NULL){
        return A;
    }
    
    ListNode* curr;
    ListNode* temp;
    
    curr = A;
    
    while(curr->next != NULL){
        temp = curr->next;
        while(curr->val == temp->val){
            if(temp->next == NULL){
                curr->next = NULL;
                return A;
            }
            temp = temp->next;
        }
        curr->next = temp;
        curr = temp;
    }
    
    return A;
}
