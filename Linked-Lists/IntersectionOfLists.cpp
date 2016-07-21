// https://www.interviewbit.com/problems/intersection-of-linked-lists/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
void findLength(ListNode* A, ListNode* B, int& lenA, int& lenB){
    while((A != NULL) || (B != NULL)){
        if(A != NULL){
            lenA++;
            A = A->next;
        }
        if(B != NULL){
            lenB++;
            B = B->next;
        }
    }
} 

ListNode* Solution::getIntersectionNode(ListNode* A, ListNode* B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int lenA = 0;
    int lenB = 0;
    
    findLength(A, B, lenA, lenB);
    
    int diff = lenA - lenB; 
    int largeB = 0;
    
    if(diff < 0){
        diff = abs(diff);
        largeB = 1;
    }
    
    if(diff != 0){
        if(largeB == 1){
            while(diff != 0){
                B = B->next;
                diff--;
            }
        }
        else{
            while(diff != 0){
                A = A->next;
                diff--;
            }       
        }
    }
    
    while(A != NULL && B != NULL){
        if(A == B){
            return A;
        }
        A = A->next;
        B = B->next;
    }
    
    return NULL;
}
