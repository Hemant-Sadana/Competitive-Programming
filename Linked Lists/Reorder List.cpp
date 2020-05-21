/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::reorderList(ListNode* A) {
    if(A==NULL || A->next == NULL)
    return A;
    ListNode* slow,*fast,*p1,*p2,*p3;
    slow = A;fast = A;
    while(fast!=NULL && fast->next!=NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    if(fast!=NULL)
    slow = slow->next;
    p1 = slow;p2 = slow;p3 = slow->next;
    slow->next = NULL;
    while(p3!=NULL)
    {
        p2 = p3;
        p3 = p3->next;
        p2->next = p1;
        p1 = p2;
    }
    p1 = A;;
    while(p2!=NULL)
    {
        slow = p1;fast = p2;
        p1 = p1->next;
        p2 = p2->next;
        slow->next = fast;
        fast->next = p1;
    }
    if(p1!=NULL)
    p1->next = NULL;
    return A;
}
