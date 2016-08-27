// https://www.interviewbit.com/problems/recover-binary-search-tree/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<int> Solution::recoverTree(TreeNode* A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    vector<int> sol;
    
    TreeNode *first = NULL, *last = NULL, *prev = NULL, *curr = A;
    
    stack<TreeNode*> st;
    bool isDone = false;
    
    while(!isDone){
        if(curr != NULL){
            st.push(curr);
            curr = curr->left;
        }
        else{
            curr = st.top();
            st.pop();
            if(prev != NULL){
                if(prev->val > curr->val){
                    if(first == NULL){
                        first = prev;
                    }    
                    last = curr;
                }
            }
            prev = curr;
            curr = curr->right;
        }
        if(st.empty() &&  curr == NULL){
           isDone = true; 
        }
    }
    
    sol.push_back(first->val);
    sol.push_back(last->val);
    
    sort(sol.begin(), sol.end());
    
    return sol;
    
}
