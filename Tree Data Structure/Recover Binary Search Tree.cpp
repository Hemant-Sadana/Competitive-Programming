/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
void inorder_morris(TreeNode* A,vector<int> &ans)
{
    TreeNode* temp;
    int prev = INT_MIN;
    while(A!=NULL)
    {
        if(A->left)
        {
            temp = A->left;
            while(temp->right!=NULL && temp->right!=A)
            {
                temp = temp->right;
            }
            if(temp->right != A)
            {
                temp->right = A;
                A = A->left;
            }
            else
            {
                temp->right = NULL;
                if(A->val<prev)
                {
                    ans.push_back(prev);
                    ans.push_back(A->val);
                }
                prev = A->val;
                A = A->right;
                }
        }
        else
        {
            if(A->val<prev)
            {
                ans.push_back(prev);
                ans.push_back(A->val);
            }
            prev = A->val;
            A = A->right;
        }
    }
}
vector<int> Solution::recoverTree(TreeNode* A) {
    vector<int> ans;
    int prev = INT_MIN;
    inorder_morris(A,ans);
    vector<int> res;
    res.push_back(ans[ans.size()-1]);
    res.push_back(ans[0]);
    return res;
}
