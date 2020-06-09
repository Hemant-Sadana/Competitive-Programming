/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
TreeNode* generate(ListNode* A)
{
    if(A == NULL)
    return NULL;
    ListNode* t1,*t2,*t3,*t4;
    t1 = A;t2 = A;t4 = NULL;
    while(t2!=NULL && t2->next!=NULL)
    {
        t4 = t1;
        t1 = t1->next;
        t2 = t2->next->next;
    }
    t3 = t1->next;
    TreeNode* root = (TreeNode*)malloc(sizeof(TreeNode));
    root->left = NULL;
    root->right = NULL;
    root->val = t1->val;
    if(t4 == NULL)
    return root;
    t4->next = NULL;
    root->left = generate(A);
    root->right = generate(t3);
    return root;
}
TreeNode* Solution::sortedListToBST(ListNode* A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    return generate(A);    
}
