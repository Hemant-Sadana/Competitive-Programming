/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<int> Solution::preorderTraversal(TreeNode* A) {
    stack<TreeNode*> s;
    TreeNode* temp;
    vector<int> ans;
    if(A==NULL)
    return ans;
    while(!s.empty() || A)
    {
        if(A==NULL)
        {
            temp = s.top();
            s.pop();
            A = temp->right;
        }
        else
        {
            ans.push_back(A->val);
            s.push(A);
            A = A->left;
        }
    }
    return ans;
}
