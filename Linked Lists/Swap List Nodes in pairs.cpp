/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::swapPairs(ListNode* A) {
    if(A==NULL || A->next==NULL)
    return A;
    ListNode* p1,*p2,*p3,*prev,*curr;
    p1 = A;p2 = A;p3 = A->next;prev = NULL;curr = p2;
    while(p3!=NULL)
    {
        curr = p2;
        p2 = p3;
        p3 = p3->next;
        p2->next = p1;
        if(prev == NULL)
        A = p2;
        else
        prev->next = p2;
        prev = curr;
        curr->next = p3;
        if(p3==NULL)
        return A;
        p2 = p3;p1 = p2;
        p3 = p3->next;
    }
    return A;
}
