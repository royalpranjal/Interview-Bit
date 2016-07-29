// https://www.interviewbit.com/problems/add-two-numbers-as-lists/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
ListNode* Solution::addTwoNumbers(ListNode* A, ListNode* B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    if(A == NULL){
        return B;
    }
    else if(B == NULL){
        return A;
    }
    
    // reversing the list
    
    ListNode* currA = A;
    ListNode* currB = B;
    
    ListNode* ans = NULL;
    ListNode* head;
    
    int sum, carry = 0, value;
    while(currA != NULL && currB != NULL){
        sum = currA->val + currB->val + carry;
        carry = sum/10;
        value = sum%10;
        
        ListNode* store = new ListNode(value);
        
        if(ans == NULL){
            ans = store;
            head = ans;
        }
        else{
            ans->next = store;
            ans = store;
        }
        currA = currA->next;
        currB = currB->next;
    }
    
    if(currA == NULL){
        while(currB != NULL){
            sum = currB->val + carry;
            carry = sum/10;
            value = sum%10;
            
            ListNode* store = new ListNode(value);
            
            ans->next = store;
            ans = store;
            
            currB = currB->next;
        }
    }
    else if(currB == NULL){
        while(currA != NULL){
            sum = currA->val + carry;
            carry = sum/10;
            value = sum%10;
            
            ListNode* store = new ListNode(value);
            
            ans->next = store;
            ans = store;
            
            currA = currA->next;
        }
    }
    
    if(carry != 0){
        ListNode* store = new ListNode(carry);
        
        ans->next = store;
        ans = store;
    }

    return head;
}
