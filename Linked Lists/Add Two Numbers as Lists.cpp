/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
int len(ListNode* ptr)
{
    int c = 0;
    while(ptr!=NULL)
    {
        ptr = ptr->next;
        c++;
    }
    return c;
}
void sum(ListNode* A,ListNode* B)
{
    ListNode* p1,*p2,*temp,*ptr;
    p1 = A;p2 = B;
    int sum = 0,carry = 0,req = 0;
    while(p2!=NULL || p1!=NULL)
    {
        req = (p2==NULL) ? (p1->val + carry) : (p1->val + p2->val + carry);
        sum = req%10;
        carry = req/10;
        p1->val = sum;
        temp = p1;
        p1 = p1->next;
        if(p2!=NULL)
        p2 = p2->next;
    }
    if(carry!=0)
    {
        ptr = (ListNode*)malloc(sizeof(ListNode));
        ptr->val = 1;ptr->next = NULL;
        temp->next = ptr;
    }
    
}
ListNode* Solution::addTwoNumbers(ListNode* A, ListNode* B) {
    int l1 = len(A);
    int l2 = len(B);
    ListNode* head;
    if(l1>=l2)
    {
        head = A;
        sum(A,B);
    }
    else
    {
        head = B;
        sum(B,A);
    }
    return head;
}
