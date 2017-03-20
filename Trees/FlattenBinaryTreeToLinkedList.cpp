/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
TreeNode* Solution::flatten(TreeNode* A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    if(A == NULL){
        return A;
    }

    stack<TreeNode*> st;
    
    TreeNode* curr = A, *last = NULL;

    do{
        if(curr != NULL){
            st.push(curr);
            if(curr == A){
                last = curr;
            }
            else{
                last->left = curr;
                last = last->left;
            }
            curr = curr->left;
        }
        else{
            curr = st.top();
            curr = curr->right;
            st.pop();
        }
    }while(!st.empty() || curr != NULL);
    
    curr = A;
    
    while(curr != NULL){
        TreeNode* temp = curr->left;
        curr->left = NULL;
        curr->right = temp;
        curr = curr->right;
    }
    
    return A;
    
}
