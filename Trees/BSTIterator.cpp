/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
stack<TreeNode*> st;
TreeNode* curr = NULL;

BSTIterator::BSTIterator(TreeNode *root) {
    while(!st.empty()){
        st.pop();
    }
    curr = root;
    while(curr != NULL){
        st.push(curr);
        curr = curr->left;
    }
}

/** @return whether we have a next smallest number */
bool BSTIterator::hasNext() {
    if(st.empty()){
        return false;
    }
    return true;
}

/** @return the next smallest number */
int BSTIterator::next() {
    if(st.empty()){
        return -1;
    }
    curr = st.top();
    int ans = curr->val;
    curr = curr->right;
    st.pop();
    while(curr != NULL){
        st.push(curr);
        curr = curr->left;
    }
    
    return ans;
}

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
