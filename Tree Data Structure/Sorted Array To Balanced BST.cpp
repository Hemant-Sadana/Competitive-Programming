/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
TreeNode* convert(const vector<int> &A,int l,int r)
{
    if(l>r)
    return NULL;
    int mid = (l+r)/2;
    TreeNode* root = (TreeNode*)malloc(sizeof(TreeNode));
    root->val = A[mid];
    root->left = convert(A,l,mid-1);
    root->right = convert(A,mid+1,r);
    return root;
}
TreeNode* Solution::sortedArrayToBST(const vector<int> &A) {
    return convert(A,0,A.size()-1);
}
