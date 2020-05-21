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
    ListNode* temp,*ptr;
    ptr = A;
    while(ptr->next!=NULL)
    {
        if(ptr->val == ptr->next->val)
        {
            temp = ptr->next;
            ptr->next = temp->next;
            free(temp);
        }
        else
        ptr = ptr->next;
    }
    return A;
}
