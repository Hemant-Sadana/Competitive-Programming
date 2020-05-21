/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::mergeTwoLists(ListNode* A, ListNode* B) {
    ListNode* p1,*p2,*head,*curr;
    if(A==NULL || B==NULL)
    return (A==NULL) ? A : B;
    p1 = A;p2 = B;curr = NULL;
    while(p1!=NULL || p2!=NULL)
    {
        if(p2 == NULL || (p1!=NULL && p1->val<=p2->val))
        {
            if(curr==NULL)
            {
                curr = A;
                head = A;
            }
            else
            {
                curr->next = p1;
                curr = curr->next;
            }
            p1 = p1->next;
        }
        else if(p1 == NULL || (p2!=NULL && p2->val<p1->val))
        
            if(curr==NULL)
            {
                curr = B;
                head = B;
            }
            else
            {
                curr->next = p2;
                curr = curr->next;
            }
            p2 = p2->next;
        }
    }
    return head;
}
