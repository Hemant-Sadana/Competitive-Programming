/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int findsum(TreeNode* A,int &ans,int sum)
{
    if(A==NULL)
    return ans;
    if(A->left == NULL && A->right == NULL)
    {
        ans = (ans + (sum*10 + A->val)%1003)%1003;
        return ans;
    }
    sum = (sum*10 + A->val)%1003;
    findsum(A->left,ans,sum);
    findsum(A->right,ans,sum);
    return ans;
}
int Solution::sumNumbers(TreeNode* A) {
    int ans = 0;
    return findsum(A,ans,0);
}
