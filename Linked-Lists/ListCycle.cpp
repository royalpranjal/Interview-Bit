// https://www.interviewbit.com/problems/list-cycle/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::detectCycle(ListNode* A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    if(A == NULL || A->next == NULL){
        return NULL;
    }
    
    ListNode* slow = A;
    ListNode* fast = A;
    
    while(slow != NULL && fast != NULL){
        slow = slow->next;
        if(fast->next == NULL){
            return NULL;
        }
        else{
            fast = (fast->next)->next;
        }
        if(slow == fast){
            break;
        }
    }
    
    if(slow == NULL || fast == NULL){
        return NULL;
    }
    
    ListNode* curr = A;
    while(curr != slow){
        curr = curr->next;
        slow = slow->next;
    }
    
    return curr;
       
}
