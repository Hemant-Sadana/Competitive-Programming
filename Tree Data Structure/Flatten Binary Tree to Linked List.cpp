/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
void flat(TreeNode* A,TreeNode* &temp)
{
    if(A==NULL)
    return;
    if(temp==NULL)
    temp = A;
    else
    {
        temp->left = A;
        temp = temp->left;
    }
    flat(A->left,temp);
    flat(A->right,temp);
    A->right = NULL;
}
void invert(TreeNode* A)
{
    while(A!=NULL)
    {
    A->right = A->left;
    A->left = NULL;
    A = A->right;
    }
}
TreeNode* Solution::flatten(TreeNode* A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    TreeNode* temp = NULL;    
    flat(A,temp);
    invert(A);
    return A;
}
