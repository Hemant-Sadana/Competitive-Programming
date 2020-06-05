/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
void store(TreeNode* A,int B,vector<int> &temp)
{
    if(A==NULL)
    return;
    store(A->left,B,temp);
    if(A->val<=B)
    temp.push_back(A->val);
    store(A->right,B,temp);
}
int Solution::t2Sum(TreeNode* A, int B) {
    vector<int> temp;
    store(A,B,temp);
    int n = temp.size(),i=0,j=n-1;
    while(i<j)
    {
        if(temp[i]+temp[j]==B)
        return 1;
        if(temp[i]+temp[j]<B)
        i++;
        else
        j--;
    }
    return 0;
}
