/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int find(TreeNode* A,int B,int sum)
{
    if(A==NULL)
    return 0;
    if(A->left == NULL && A->right==NULL)
    {
        sum += A->val;
        if(sum == B)
        return 1;
        return 0;
    }
    sum += A->val;
    return find(A->left,B,sum) || find(A->right,B,sum);
}
int Solution::hasPathSum(TreeNode* A, int B) {
    return find(A,B,0);
}
