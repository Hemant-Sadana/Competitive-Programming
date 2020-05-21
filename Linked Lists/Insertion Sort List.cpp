/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::insertionSortList(ListNode* A) {
    ListNode* p1,*p2,*p3,*temp;
    p1 = A;p3 = NULL;
    while(p1)
    {
        p2 = p1;
        p1 = p1->next;
        if(p3 == NULL || p3->val > p2->val)
        {
            p2->next = p3;
            p3 = p2;
        }
        else
        {
            temp = p3;
            while(temp->next!=NULL && temp->next->val <= p2->val)
            temp = temp->next;
            p2->next = temp->next;
            temp->next = p2;
        }
    }
    return p3;
}
