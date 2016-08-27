// https://www.interviewbit.com/problems/sort-list/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* merge(ListNode* A, ListNode* B){
    if(A == NULL){
        return B;
    }
    if(B == NULL){
        return A;
    }
    
    ListNode* head = NULL;
    
    if(A->val < B->val){
        head = A;
        A = A->next;
    }
    else{
        head = B;
        B = B->next;
    }
    
    ListNode* temp = head;
    
    while(A != NULL && B != NULL){
        if(A->val < B->val){
            temp->next = A;
            A = A->next;
        }
        else{
            temp->next = B;
            B = B->next;
        }
        temp = temp->next;
    }
    
    if(A != NULL){
        temp->next = A;
    }
    else{
        temp->next = B;
    }
    
    return head;
} 

ListNode* Solution::sortList(ListNode* A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    ListNode* head = A;
    
    if(head == NULL || head->next == NULL){
        return head;
    }
    
    ListNode* start = A;
    ListNode* end = A->next;
    
    while(end != NULL && end->next != NULL){
        start = start->next;
        end = (end->next)->next;
    }
    
    end = start->next;
    start->next = NULL;
    
    return merge(sortList(head), sortList(end)); 
}
