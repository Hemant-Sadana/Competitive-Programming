/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<vector<int> > Solution::levelOrder(TreeNode* A) {
    vector<vector<int> > ans;
    if(A==NULL)
    return ans;
    vector<int> temp;
    TreeNode* ptr;
    queue<TreeNode*> q;
    q.push(A);
    int n;
    while(!q.empty())
    {
        n = q.size();
        for(int i=0;i<n;i++)
        {
            ptr = q.front();
            q.pop();
            temp.push_back(ptr->val);
            if(ptr->left)
            q.push(ptr->left);
            if(ptr->right)
            q.push(ptr->right);
        }
        ans.push_back(temp);
        temp.clear();
    }
    return ans;
}
