/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::mergeKLists(vector<ListNode*> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    ListNode* head,*curr;
    head = NULL;
    int m = INT_MAX,index;
    while(1)
    {
        m = INT_MAX;index = -1;
        for(int i=0;i<A.size();i++)
        {
            if(A[i]!=NULL && A[i]->val<m)
            {
                m = A[i]->val;
                index = i;
            }
        }
        if(index == -1)
        return head;
        if(head == NULL)
        {
            head = A[index];
            curr = A[index];
        }
        else
        {
            curr->next = A[index];
            curr = curr->next;
        }
        A[index] = A[index]->next;
        curr->next = NULL;
    }
}
