/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::reverseList(ListNode* A, int B) {
    if(A==NULL || A->next==NULL)
    return A;
    ListNode* p1,*p2,*p3,*prev,*start;
    p1 = A;p2 = A;p3 = p1->next;prev = NULL;start = A;
    int x = B;
    while(p3!=NULL)
    {
        start = p2;
        while(x!=1)
        {
            x--;
            p2 = p3;
            p3 = p3->next;
            p2->next = p1;
            p1 = p2;
        }
        x = B;
        if(prev == NULL)
        A = p2;
        else
        prev->next = p2;
        prev = start;
        start->next = p3;
        if(p3==NULL)
        return A;
        p2 = p3;
        p1 = p2;
        p3 = p3->next;
    }
}
