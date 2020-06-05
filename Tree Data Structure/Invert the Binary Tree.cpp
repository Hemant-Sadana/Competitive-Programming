/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
void Invert(TreeNode* A)
{
    if(A==NULL)
    return;
    swap(A->left,A->right);
    Invert(A->left);
    Invert(A->right);
}
TreeNode* Solution::invertTree(TreeNode* A) {
    Invert(A);
    return A;
}
