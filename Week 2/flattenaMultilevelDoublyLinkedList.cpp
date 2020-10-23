/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    public:
    Node* flatten(Node* head)
    {
        Node* ptr=head;
        while(ptr!=NULL)
        {
            if(ptr->child!=NULL)
            {
                Node* temp=ptr->next;
                ptr->next=flatten(ptr->child);
                ptr->child=NULL;
                (ptr->next)->prev=ptr;
                Node* temp1=last(ptr->next);
                temp1->next=temp;
                if(temp!=NULL)
                temp->prev=temp1;
                ptr=temp;
            }else
                ptr=ptr->next;
        }
    return head;
}
    
    Node* last(Node* head)
    {
        if(head==NULL||head->next==NULL)
            return head;
        while(head->next!=NULL)
        {
            head=head->next;
        }
    return head;
    }
    
};

