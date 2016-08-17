// https://www.interviewbit.com/problems/inorder-traversal-of-cartesian-tree/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int findMax(vector<int> &A, int start, int end){
    int max = A[start];
    int index = start;
    for(int i = start; i <= end; i++){
        if(max < A[i]){
            max = A[i];
            index = i;
        }
    }
    return index;
} 

TreeNode* makeCart(vector<int> &A, int start, int end){
    if(start > end){
        return NULL;
    }
    
    int maxIn = findMax(A, start, end);
    
    TreeNode* root = new TreeNode(A[maxIn]);
    
    root->left = makeCart(A, start, maxIn-1);
    root->right = makeCart(A, maxIn+1, end);
    
    return root;
}

TreeNode* Solution::buildTree(vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    return makeCart(A, 0, A.size()-1);
}
