// https://www.interviewbit.com/problems/remove-duplicates-from-sorted-list-ii/

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
    
    ListNode* curr = A;
    ListNode* nxt = A->next;
    ListNode* prev = NULL;
    ListNode* temp;
    ListNode* head = A;
    
    int flag = 0;
    int flag1 = 1;
    
    if(nxt != NULL){
        if(curr->val == nxt->val){
            flag = 1;
        } 
    }
    
    LOOP:while(nxt != NULL){
        if(flag == 0){
            if(flag1 != 0){
                prev = curr;
            }
            curr = nxt;
        }
        nxt = nxt->next;
        if(nxt == NULL){
            goto CONDITION;
        }
        if(curr->val == nxt->val){
            flag = 1;
            goto LOOP;    
        }
        else{
            flag1 = 1;
        }
        CONDITION:if(flag == 1){
            if(prev != NULL){
                prev->next = nxt;
            }
            else{
                head = nxt;
            }
            flag1 = 0;
            flag = 0;
        }
    }
    
    return head;
    
}
