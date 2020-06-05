/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
void find(TreeNode* A,int B,int sum,vector<int> temp,vector<vector<int> > &ans)
{
    if(A==NULL)
    return;
    if(A->left == NULL && A->right == NULL)
    {
        if(sum + A->val == B)
        {
            temp.push_back(A->val);
            ans.push_back(temp);
        }
        return;
    }
    sum += A->val;
    temp.push_back(A->val);
    find(A->left,B,sum,temp,ans);
    find(A->right,B,sum,temp,ans);
}
vector<vector<int> > Solution::pathSum(TreeNode* A, int B) {
    vector<vector<int> > ans;
    vector<int> temp;
    find(A,B,0,temp,ans);
    return ans;
}
