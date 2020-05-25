/**
 * Definition for singly-linked list.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
RandomListNode* Solution::copyRandomList(RandomListNode* A) {
    RandomListNode* temp,*head,*ptr,*curr;
    temp = A;
    head = NULL;
    map<RandomListNode*,RandomListNode*> hash;
    while(temp!=NULL)
    {
        ptr = (RandomListNode*)malloc(sizeof(RandomListNode));
        ptr->label = temp->label;
        ptr->next = NULL;
        ptr->random = NULL;
        if(head == NULL)
        {
            head = ptr;
            curr = ptr;
        }
        else
        {
            curr->next = ptr;
            curr = curr->next;
        }
        hash[temp] = ptr;
        temp = temp->next;
    }
    temp = A;
    ptr = head;
    while(temp!=NULL)
    {
        if(temp->random == NULL)
        ptr->random = NULL;
        else
        ptr->random = hash[temp->random];
        temp = temp->next;
        ptr = ptr->next;
    }
    return head;
}
