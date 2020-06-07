/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
void find(TreeNode* A,int B,int C,vector<vector<int> > &ans,vector<int> temp,int &f)
{
    if(A==NULL)
    return;
    temp.push_back(A->val);
    if(A->val == B || A->val == C)
    {
        f++;
        ans.push_back(temp);
    }
    find(A->left,B,C,ans,temp,f);
    find(A->right,B,C,ans,temp,f); 
}
int Solution::lca(TreeNode* A, int B, int C) {
    vector<vector<int> > ans;
    vector<int> temp;
    int f = 0;
    find(A,B,C,ans,temp,f);
    if(B==C && f>0)
    return B;
    if(f<2)
    return -1;
    int n = min(ans[0].size(),ans[1].size());
    int i = n-1,j=n-1;
    while(1)
    {
        if(ans[0][i]==ans[1][j])
        return ans[0][i];
        i--;j--;
    }
}
