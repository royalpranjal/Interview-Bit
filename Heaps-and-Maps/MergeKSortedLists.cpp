// https://www.interviewbit.com/problems/merge-k-sorted-lists/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::mergeKLists(vector<ListNode*> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    map<int, int> myMap;
    
    for(int i = 0; i < A.size(); i++){
        ListNode* curr = A[i];
        while(curr != NULL){
            int temp = curr->val;
            if(myMap.find(temp) != myMap.end()){
                myMap[temp]++;
            }
            else{
                myMap[temp] = 1;
            }
            curr = curr->next;
        }
    }
    
    auto it = myMap.begin();
    
    ListNode* head = NULL;
    ListNode* curr = NULL;
    
    while(it != myMap.end()){
        while(it->second != 0){
            ListNode* list = new ListNode(it->first);
            if(head == NULL){
                head = list;
                curr = list;
            }
            else{
                curr->next = list;
                curr = curr->next;
            }
            it->second--;
        }
        it++;
    }
    
    return head;
    
}
