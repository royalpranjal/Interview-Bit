// https://www.interviewbit.com/problems/insertion-sort-list/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::insertionSortList(ListNode* A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    if(A == NULL){
        return A;
    }
    
    ListNode* curr = A->next;
    ListNode* temp;
    ListNode* prev = A;
    ListNode* head = A;
    ListNode* check;
    ListNode* checkPrev;
    
    while(curr != NULL){
        temp = curr->next;
        if(curr->val < prev->val){
            check = head;
            checkPrev = NULL;
            while(check != curr){
                if(check->val > curr->val){
                    break;
                }
                checkPrev = check;
                check = check->next;
            }
            if(checkPrev == NULL){
                head = curr;
                curr->next = check;
                prev->next = temp;
                curr = temp;
            }
            else{
                checkPrev->next = curr;
                curr->next = check;
                prev->next = temp;
                curr = temp;
            }
        }
        else{
            prev = curr;
            curr = temp;
        }
    }
    
    return head;
}
