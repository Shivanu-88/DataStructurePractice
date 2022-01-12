Node *Reverse(Node *head)
{
    if(head==NULL || head->next==NULL)
    {
        return head;
    }
    Node *newhead=Reverse(head->next);
    Node *headnext=head->next;
    headnext->next=head;
    head->next=NULL;
    return newhead;
}