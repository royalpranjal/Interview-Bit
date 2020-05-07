int Solution::minDepth(TreeNode* A) {
    if(!A)return 0;
    if(!A->left and !A->right) return 1;
    if(!A->left)return minDepth(A->right) + 1;
    if(!A->right)return minDepth(A->left) + 1;
    return min(minDepth(A->left), minDepth(A->right)) + 1;
}
