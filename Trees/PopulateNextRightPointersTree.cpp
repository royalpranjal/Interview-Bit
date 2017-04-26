/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
void Solution::connect(TreeLinkNode* A) {
    if(A == NULL){
        return;
    }
    
    if(A->left != NULL){
        if(A->right != NULL){
            (A->left)->next = A->right;
        }
        else{
            TreeLinkNode* temp = A;
            while(temp->next != NULL){
                if((temp->next)->left != NULL){
                    (A->left)->next = (temp->next)->left;
                    break;
                }
                else if((temp->next)->right != NULL){
                    (A->left)->next = (temp->next)->right;
                    break;
                } 
                temp = temp->next;
            }    
        }
    }
    
    if(A->right != NULL){
        TreeLinkNode* temp = A;
        while(temp->next != NULL){
            if((temp->next)->left != NULL){
                (A->right)->next = (temp->next)->left;
                break;
            }
            else if((temp->next)->right != NULL){
                (A->right)->next = (temp->next)->right;
                break;
            } 
            temp = temp->next;
        }    
    }
    
    
    connect(A->right);
    connect(A->left);
}
