/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::partition(ListNode* A, int B) {
    ListNode* p1,*p2,*prev,*temp;
    p1 = A;p2 = NULL;
    while(p1!=NULL && p1->val<B)
    {
        p2 = p1;
        p1 = p1->next;
    }
    prev = p2;
    while(p1!=NULL)
    {
        if(p1->val<B)
        {
            temp = p1->next;
            if(p2 == NULL)
            {
                p1->next = A;
                
                A = p1;
                p2 = p1;
            }
            else
            {
                p1->next = p2->next;
                p2->next = p1;
                p2 = p2->next;
                
            }
            p1 = temp;
            prev->next = temp;
        }
        else
        {
            if(prev==NULL)
            prev = A;
            else
            prev = prev->next;
            p1 = p1->next;
        }
    }
    return A;
}
