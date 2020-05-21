/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* merge(ListNode* p1,ListNode* p2)
{
    ListNode* head,*curr;
    head = NULL;
    if(p1->val<=p2->val)
    {
        head = p1;p1 = p1->next;
    }
    else
    {
        head = p2;p2 = p2->next;
    }
    curr = head;
    while(p1!=NULL && p2!=NULL)
    {
        if(p1->val<=p2->val)
        {
            curr->next = p1;p1 = p1->next;curr = curr->next;
        }
        else
        {
            curr->next = p2;p2 = p2->next;curr = curr->next;
        }
    }
    if(p1!=NULL)
    curr->next = p1;
    if(p2!=NULL)
    curr->next = p2;
    return head;
}
ListNode* mergesort(ListNode* A)
{
    if(A==NULL || A->next == NULL)
    return A;
    ListNode* p1,*p2,*p3;
    p1 = A;p2 = A->next->next;
    while(p2!=NULL && p2->next!=NULL)
    {
        p1 = p1->next;
        p2 = p2->next->next;
    }
    p3 = p1->next;
    p1->next = NULL;
    A = mergesort(A);
    p3 = mergesort(p3);
    return merge(A,p3);
}
ListNode* Solution::sortList(ListNode* A) {
    return mergesort(A);
}
