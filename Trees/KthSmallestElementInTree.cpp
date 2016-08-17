// https://www.interviewbit.com/problems/kth-smallest-element-in-tree/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int Solution::kthsmallest(TreeNode* root, int k) {
    
    if(root == NULL){
        return -1;
    }
    
    vector<int> sol;
    stack<TreeNode*> st;
    TreeNode* curr = root;
    do{
        if(curr == NULL){
            curr = st.top();
            sol.push_back(curr->val);
            st.pop();
            curr = curr->right;
            if(curr != NULL){
                st.push(curr);
                curr = curr->left;
            }
        }
        else{
            st.push(curr);
            curr = curr->left;
        }
    }while(!st.empty());
    
    return sol[k-1];
}
