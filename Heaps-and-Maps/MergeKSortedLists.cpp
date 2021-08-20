/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
struct Compare
{
    bool operator()(ListNode* const& a, ListNode* const& b)
    {
        return a->val > b->val;
    }
};
ListNode* Solution::mergeKLists(vector<ListNode*> &A) {
    priority_queue<ListNode*, vector<ListNode*>, Compare>pq;
    if(A.empty()) return NULL;
    ListNode* head = new ListNode(0);
    ListNode* curr = head;
    for(auto i = 0; i < A.size(); i++){
        pq.emplace(A[i]);
    }
    while (!pq.empty()){
        curr->next = pq.top();
        pq.pop();
        curr = curr->next;
        if(curr->next) pq.emplace(curr->next);
    }
    return head->next;
}
