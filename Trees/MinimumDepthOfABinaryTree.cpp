/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int Solution::minDepth(TreeNode* A) {
    if(A==NULL) return INT_MAX;
    if(A->left==NULL && A->right==NULL) return 1;
    return min(minDepth(A->left),minDepth(A->right))+1;
}
