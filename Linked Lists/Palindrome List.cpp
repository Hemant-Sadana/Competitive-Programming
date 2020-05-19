/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
int Solution::lPalin(ListNode* A) {
    ListNode* p1,*p2,*t1,*t2,*t3;
    p1 = A;p2 = A;
    while(p2!=NULL && p2->next!=NULL)
    {
        p1 = p1->next;
        p2 = p2->next->next;
    }
    if(p2!=NULL)
    p1 = p1->next;
    t1 = NULL;t2 = t1;t3 = p1;
    while(t3!=NULL)
    {
        t2 = t3;
        t3 = t3->next;
        t2->next = t1;
        t1 = t2;
    }
    p1 = t2;t1 = A;
    while(p1!=NULL)
    {
        if(p1->val!=t1->val)
        return 0;
        p1 = p1->next;
        t1 = t1->next;
    }
    return 1;
}
