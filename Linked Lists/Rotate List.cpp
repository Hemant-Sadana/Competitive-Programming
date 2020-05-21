/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::rotateRight(ListNode* A, int B) {
    ListNode* ptr,*temp,*h;
    ptr = A;
    int c = 0;
    while(ptr!=NULL)
    {
        ptr = ptr->next;c++;
    }
    B = B%c;
    if(B==0)
    return A;
    c = c-B;
    ptr = A;
    while(c!=1)
    {
        c--;ptr = ptr->next;
    }
    temp = ptr->next;
    h = temp;
    ptr->next = NULL;
    while(temp->next!=NULL)
    temp = temp->next;
    temp->next = A;
    A = h;
    return A;
}
