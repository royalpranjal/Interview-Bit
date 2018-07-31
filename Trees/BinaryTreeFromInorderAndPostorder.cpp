/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int search(vector<int> &in, int str, int end, int val){
    for(int k=str; k<=end; k++)
        if(in[k] == val)
            return k;
}

TreeNode* getTre(vector<int> &post, vector<int> &in, int start, int end, int &treeIndex){

    if(start > end)
        return NULL;

    TreeNode* node = new TreeNode(post[treeIndex--]);

    if(start == end)
        return node;

    int root = search(in, start, end, node->val);

    node->right = getTre(post, in, root+1, end, treeIndex);
    node->left = getTre(post, in, start, root-1, treeIndex);

    return node;
}

TreeNode* Solution::buildTree(vector<int> &in, vector<int> &post) {
    int treeIndex = in.size()-1;
    return getTre(post, in, 0, in.size()-1, treeIndex);
}
