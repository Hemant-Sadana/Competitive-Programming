/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int depth(TreeNode* A)
{
    if(A==NULL)
    return 0;
    return 1 + max(depth(A->left),depth(A->right));
}
int Solution::maxDepth(TreeNode* A) {
    return depth(A);
}
