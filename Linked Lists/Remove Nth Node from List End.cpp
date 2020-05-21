/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::removeNthFromEnd(ListNode* A, int B) {
    if(A==NULL)
    return A;
    ListNode* ptr,*temp;
    ptr = A;
    int c = 0;
    while(ptr!=NULL)
    {
        c++;ptr = ptr->next;
    }
   if(B>=c)
   {
       temp = A;
       A = A->next;
       free(temp);
       return A;
   }
    c = c-B;ptr = A;
    while(c!=1)
    {
        c--;ptr = ptr->next;
    }
    temp = ptr->next;
    ptr->next  = temp->next;
    free(temp);
    return A;
}
