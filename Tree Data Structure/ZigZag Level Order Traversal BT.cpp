/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<vector<int> > Solution::zigzagLevelOrder(TreeNode* A) {
    queue<TreeNode*> q;
    TreeNode* t;
    vector<int> temp;
    vector<vector<int> > ans;
    if(A==NULL)
    return ans;
    q.push(A);
    int n,c=0;
    while(!q.empty())
    {
        n = q.size();
        for(int i=0;i<n;i++)
        {
            t = q.front();
            q.pop();
            temp.push_back(t->val);
            if(t->left!=NULL)
            q.push(t->left);
            if(t->right!=NULL)
            q.push(t->right);
        }
        if(c%2)
        reverse(temp.begin(),temp.end());
        ans.push_back(temp);
        temp.clear();
        c++;
    }
    return ans;
}
