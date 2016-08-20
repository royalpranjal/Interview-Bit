// https://www.interviewbit.com/problems/postorder-traversal/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<int> Solution::postorderTraversal(TreeNode* A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    vector<int> sol;
    
    stack<TreeNode*> st;
    
    TreeNode* curr = A;
    TreeNode* temp;
    
    do{
        if(curr == NULL){
            temp = st.top();
            curr = temp->right;
            if(curr == NULL){
                sol.push_back(temp->val);
                st.pop();
                if(st.empty()){
                    return sol;
                }
                curr = st.top();
                while(curr->right == temp){
                    temp = curr;
                    sol.push_back(curr->val);
                    st.pop();
                    if(st.empty()){
                        return sol;
                    }
                    curr = st.top();
                }
                curr = curr->right;    
            }
        }
        else{
            st.push(curr);
            curr = curr->left;
        }
    }while(!st.empty());

    return sol;
    
}
