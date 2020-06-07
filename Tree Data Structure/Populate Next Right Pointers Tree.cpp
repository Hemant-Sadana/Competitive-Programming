/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
void Solution::connect(TreeLinkNode* A) {
    TreeLinkNode* ptr,*temp;
    ptr = NULL;temp = NULL;
    while(A!=NULL)
    {
        while(A!=NULL)
        {
            if(A->left)
            {
                if(ptr == NULL)
                {
                    ptr = A->left;
                }
                else
                {
                    ptr->next = A->left;
                    ptr = ptr->next;
                }
                if(temp == NULL)
                temp = A->left;
            }
            if(A->right)
            {
                if(ptr == NULL)
                {
                    ptr = A->right;
                }
                else
                {
                    ptr->next = A->right;
                    ptr = ptr->next;
                }
                if(temp == NULL)
                temp = A->right;
            }
            A = A->next;
        }
        A = temp;
        temp = NULL;
        ptr = NULL;
    }
}
