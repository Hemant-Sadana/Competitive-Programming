/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
TreeNode* build(vector<int> &A,vector<int> &B,int l,int r,int &j)
{
    if(l>r)
    return NULL;
    int index;
    for(int i=l;i<=r;i++)
    {
        if(A[i]==B[j])
        {
            index = i;
            break;
        }
    }
    TreeNode* root = (TreeNode*)malloc(sizeof(TreeNode));
    root->val = B[j];
    j--;
    root->right = build(A,B,index+1,r,j);
    root->left = build(A,B,l,index-1,j);
    return root;
}
TreeNode* Solution::buildTree(vector<int> &A, vector<int> &B) {
    int j = A.size()-1;
    return build(A,B,0,A.size()-1,j);
}
