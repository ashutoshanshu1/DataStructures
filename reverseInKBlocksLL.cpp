//  11->22->33->44->55->66->77->88->99->x

Node* reverseLLinKGroups(Node* head, int k)
{

    Node* temp=head;        // for traversal
    Node* prevLast=NULL;    // end of previous segment

    while(temp!=NULL)
    {
        Node* kthNode=getKThNode(temp,k);
    }


    
    Node* nextNode=KthNode->next;
    KthNode->next = NULL;

    classicReverse(temp);


    // if this was the first reversal i.e. first segment, there will be a new head
    if(temp==head)
    {
        head=KthNode;   // new head
    }
    else{
        prevLast->next=KthNode;
    }
    classicReverse(getKPlusOneThNode);
}

//  11 -> 22 -> 33 -> 44 -> 55 -> 66 -> 77 -> 88 -> 99 -> x
Node* getKThNode(Node* head, int k)
{
    int i=0;
    Node* kPlusOneNode=head;
    while(i<k-1)
    {
        kPlusOneNode=kThNode->next;
        i++;
    }
    return kPlusOneNode;
}

Node* classicReverse(Node* head)
{   
    Node* prev=NULL;        // One behind
    Node* current=head;     // one current
    while(current!=NULL)
    {
        Node* fwd=current->next;    // one ahead
        current->next=prev;
        prev=current;
        current=fwd;
    }
    return prev;    // new Head
}