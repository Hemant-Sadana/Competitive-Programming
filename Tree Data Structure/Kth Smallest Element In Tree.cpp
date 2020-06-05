/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int find(TreeNode* A,int &B,int &ans)
{
    if(A==NULL || B == 0)
    return ans;
    find(A->left,B,ans);
    B--;
    if(B==0)
    {
        ans = A->val;
        return ans;
    }
    find(A->right,B,ans);
    return ans;
}
int Solution::kthsmallest(TreeNode* A, int B) {
    int ans = 0;
    find(A,B,ans);
    return ans;
}
