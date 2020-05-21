/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::reverseBetween(ListNode* A, int B, int C) {
    ListNode* ptr1,*ptr2,*ptr3,*s;
    if(B==C)
    return A;
    ptr1= A;ptr2 = NULL;s = NULL;
    int x=B;
    while(B!=1)
    {
        B--;
        ptr2 = ptr1;
        ptr1 = ptr1->next;
    }
    s = ptr2;
    if(ptr2!=NULL)
    ptr2 = ptr2->next;
    else
    ptr2 = A;
    ptr3 = ptr2;
    ptr1 = ptr1->next;
    while(x!=C)
    {
        ptr2 = ptr1;
        ptr1 = ptr1->next;
        ptr2->next = ptr3;;
        ptr3 = ptr2;
        x++;
    }
    if(s!=NULL)
    {
        s->next->next = ptr1;
        s->next = ptr2;
    }
    else
    {
        A->next = ptr1;
        A = ptr2;
    }
    return A;
}
