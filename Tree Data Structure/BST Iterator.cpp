/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
TreeNode* r;
stack<TreeNode*> s;
BSTIterator::BSTIterator(TreeNode *root) {
    r = root;
    while(!s.empty())
    s.pop();
}

/** @return whether we have a next smallest number */
bool BSTIterator::hasNext() {
    if(r || !s.empty())
    return true;
    return false;
}

/** @return the next smallest number */
int BSTIterator::next() {
    TreeNode* temp;
    while(!s.empty() || r)
    {
        if(r==NULL)
        {
            temp = s.top();
            s.pop();
            r = temp->right;
            return temp->val;
        }
        else
        {
            s.push(r);
            r = r->left;
        }
    }
}

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
