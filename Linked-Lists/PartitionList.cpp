// https://www.interviewbit.com/problems/partition-list/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::partition(ListNode* A, int B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    if(A == NULL){
        return A;
    }
    
    ListNode* part = A;
    ListNode* curr = A;
    ListNode* start;
    ListNode* prev;
    ListNode* temp;
    ListNode* less_next;
    ListNode* head = A;
    
    int part_pos = 1;
    int curr_pos = 1;
    
    while(part->val < B){
        part = part->next;
        part_pos++;
        if(part == NULL){
            return head;
        }
    }
    
    LOOP:while(curr != NULL){
        temp = curr->next;
        if(curr == part){
            prev = curr;
            curr = temp;
            curr_pos++;
            goto LOOP;
        }
        else if(curr->val < B){
            if(curr_pos > part_pos){
                if(start != NULL){
                    start->next = curr;
                    curr->next = less_next;
                    prev->next = temp;
                    start = curr;
                    curr = temp;
                    curr_pos++;
                    part_pos++;
                    goto LOOP;
                }
                else{
                    curr->next = part;
                    prev->next = temp;
                    less_next = part;
                    start = curr;
                    head = curr;
                    curr = temp;
                    curr_pos++;
                    part_pos++;
                    goto LOOP;
                }
            }
            else{
                start = curr;
                less_next = temp;
                prev = curr;
                curr = temp;
                curr_pos++;
                goto LOOP;
            }
        }
        prev = curr;
        curr = temp;
        curr_pos++;
    }
    
    return head;
    
}
