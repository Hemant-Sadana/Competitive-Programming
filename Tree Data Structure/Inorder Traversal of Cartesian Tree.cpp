/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
TreeNode* build(vector<int> &A,int l,int r)
{
    if(l>r)
    return NULL;
    int mid = INT_MIN,index;
    for(int i=l;i<=r;i++)
    {
        if(A[i]>mid)
        {   
            mid = A[i];
            index = i;
        }
    }
    TreeNode* root = (TreeNode*)malloc(sizeof(TreeNode));
    root->val  = A[index];
    root->left = build(A,l,index-1);
    root->right = build(A,index+1,r);
    return root;
}
TreeNode* Solution::buildTree(vector<int> &A) {
    return build(A,0,A.size()-1);
}
