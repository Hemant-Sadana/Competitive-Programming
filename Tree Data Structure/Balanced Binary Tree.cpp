/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int f = 1;
int find(TreeNode* A)
{
    if(A==NULL || f==0)
    return 0;
    int a = 1 + find(A->left);
    int b = 1 + find(A->right);
    if(abs(a-b)>=2)
    f = 0;
    return max(a,b);
}
int Solution::isBalanced(TreeNode* A) {
    if(A==NULL)
    return 1;
    f = 1;
    find(A);
    return f;
}
