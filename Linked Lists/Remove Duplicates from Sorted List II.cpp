/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::deleteDuplicates(ListNode* A) {
    if(A==NULL)
    return A;
    ListNode* temp,*ptr,*prev;
    ptr = A;prev = NULL;
    int f = 0;
    while(ptr!=NULL)
    {
        if(ptr->next!=NULL && ptr->val==ptr->next->val)
        {
            f = 1;
            temp = ptr->next;
            ptr->next = temp->next;
            free(temp);
        }
        else
        {
            if(f==1)
            {
                temp = ptr;
                ptr = ptr->next;   
                if(prev!=NULL)
                prev->next = temp->next;
                else
                A = ptr;
                free(temp);
                f = 0;
            }
            else
            {
                prev = ptr;
                ptr = ptr->next;
            }
        }
    }
    return A;
}
