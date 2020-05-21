/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::detectCycle(ListNode* A) {
    ListNode* slow,*fast;
    if(A==NULL || A->next == NULL)
    return NULL;
    slow = A->next;
    fast = A->next->next;
    while(slow!=fast)
    {
        if(fast == NULL || fast->next == NULL)
        return NULL;
        slow = slow->next;
        fast = fast->next->next;
    }
    slow = A;
    while(slow!=fast)
    {
        slow = slow->next;
        fast = fast->next;
    }
    return slow;
}
