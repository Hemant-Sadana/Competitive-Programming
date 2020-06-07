/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int Solution::t2Sum(TreeNode* A, int B) {
    if(A==NULL)
    return 0;
    stack<TreeNode*> s1,s2;
    TreeNode* t1,*t2;
    t1 = A;t2 = A;
    while(t1!=NULL)
    {
        s1.push(t1);
        t1 = t1->left;
    }
    while(t2!=NULL)
    {
        s2.push(t2);
        t2 = t2->right;
    }
    t1 = s1.top();t2 = s2.top();
    while(t1->val<t2->val)
    {
        if(t1->val + t2->val == B)
        return 1;
        if(t1->val + t2->val < B)
        {
            s1.pop();
            t1 = t1->right;
            while(t1)
            {
                s1.push(t1);
                t1 = t1->left;
            }
            t1 = s1.top();
        }
        else
        {
            s2.pop();
            t2 = t2->left;
            while(t2)
            {
                s2.push(t2);
                t2 = t2->right;
            }
            t2 = s2.top();
        }
    }
    return 0;
}
