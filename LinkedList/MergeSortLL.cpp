Node *Midpoint(Node *curr,Node **first,Node **second)
{
    Node *slow;
    Node *fast;
    slow=curr;
    fast=curr->next;
    if(fast!=NULL)
    {
        fast=fast->next;
        if(fast!=NULL)
        {
            slow=slow->next;
            fast=fast->next;
        }
    }
    *first=curr;
    *second=slow->next;
    slow->next=NULL;
}
Node *Merge(Node *first,Node *second)
{
    Node *answer;
    if(first==NULL)
        return second;
    else if(second==NULL)
        return first;
    if(first->data<=second->data)
    {
        answer=first;
        answer->next=Merge(first->next,second);
    }
    else
    {
        answer=second;
        answer->next=Merge(first,second->next);
    }
    return answer;
}
void MergeSorting(Node **head)
{
   Node *curr=*head;
   Node *first;
   Node *second;
   if(curr==NULL || curr->next==NULL)
    return;
   Midpoint(curr,&first,&second);
   MergeSorting(&first);
   MergeSorting(&second);
   *head=Merge(first,second);
}

Node *mergeSort(Node *head)
{
	//Write your code here
    MergeSorting(&head);
    return head;
}
