/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<int> Solution::postorderTraversal(TreeNode* A) {
    stack<TreeNode*> s;
    TreeNode* temp;
    vector<int> ans;
    while(!s.empty() || A)
    {
        if(A==NULL)
        {
            temp = s.top();
            s.pop();
            A = temp->left;
        }
        else
        {
            ans.push_back(A->val);
            s.push(A);
            A = A->right;
        }
    }
    reverse(ans.begin(),ans.end());
    return ans;
}
