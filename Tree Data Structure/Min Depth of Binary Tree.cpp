/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
void depth(TreeNode* A,int &ans,int c)
{
    if(A==NULL)
    return;
    if(A->left == NULL && A->right == NULL)
    {
        if(c+1<ans)
        ans = c+1;
        return;
    }
    depth(A->left,ans,c+1);
    depth(A->right,ans,c+1);
}
int Solution::minDepth(TreeNode* A) {
    int ans = INT_MAX;
    depth(A,ans,0);
    return (ans == INT_MAX) ? 0 : ans;
}
