/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<int> Solution::inorderTraversal(TreeNode* A) {
    stack<TreeNode*> s;
    TreeNode* temp;
    vector<int> ans;
    while(!s.empty() || A)
    {
        if(A==NULL)
        {
            temp = s.top();
            s.pop();
            ans.push_back(temp->val);
            A = temp->right;
        }
        else
        {
            s.push(A);
            A = A->left;
        }
    }
    return ans;
}
