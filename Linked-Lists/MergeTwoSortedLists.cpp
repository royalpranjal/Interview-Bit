// https://www.interviewbit.com/problems/merge-two-sorted-lists/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::mergeTwoLists(ListNode* A, ListNode* B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    ListNode* prevA;
    ListNode* currA; 
    ListNode* tempA;
    ListNode* prevB; 
    ListNode* currB; 
    ListNode* tempB;
    
    currA = A;
    currB = B;
    prevA = NULL;
    prevB = NULL;
    
    if(A == NULL){
        return B;
    }
    else if(B == NULL){
        return A;
    }
    
    int retA = 1; 
    
    if(currA->val > currB->val){
        retA = 0;
    }
    
    // changes in list A
    while(currA != NULL && currB != NULL){
        if(currA->val == currB->val){
            prevA = currA;
            tempA = currA->next;
            currA->next = currB;
            
            prevB = currB;
            currA = prevB;
            tempB = currB->next;
            currB->next = tempA;
            currB = tempB;
        }
        else if(currA->val > currB->val){
            if(prevA != NULL){
                prevA->next = currB;
            }
            prevA = currB;
            prevB = currB;
            tempB = currB->next;
            currB->next = currA;
            currB = tempB;
            
        }
        else if(currA->val < currB->val){
            prevA = currA;
            currA = currA->next;
        }
    }
    
    if(currB != NULL && currA == NULL){
        prevA->next = currB;
    }
    
    if(retA == 0){
        return B;
    }
    
    return A;
}
