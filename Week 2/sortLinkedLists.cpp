/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* merge(ListNode* headA,ListNode* headB)
    {
        if(headA==NULL)
        {
            return headB;
        }
        else if(headB==NULL)
        {
            return headA;
        }

        else
        {
            ListNode* nhead=NULL;
            if(headA->val<headB->val)
            {
                //cout<<"if"<<endl;
                //cout<<"headA : "<<headA->data<<endl;
                //cout<<"headB : "<<headB->data<<endl;
                nhead=headA;
                nhead->next=merge(headA->next,headB);
            }
            else
            {
                //cout<<"else"<<endl;
                //cout<<"headA : "<<headA->data<<endl;
                //cout<<"headB : "<<headB->data<<endl;
                nhead=headB;
                nhead->next=merge(headA,headB->next);
            }
            return nhead;
        }
    }
    
    ListNode* mid(ListNode* head)
    {
        ListNode* slow=head;
        ListNode* fast=head->next;

        while(fast && fast->next)
        {
            slow=slow->next;
            fast=fast->next->next;
        }

        return slow;
    }
    
    ListNode* sortList(ListNode* head) {
        if(head==NULL || head->next==NULL)
        {
            return head;
        }

        ListNode* m=mid(head);
        ListNode* a=head;
        ListNode* b=m->next;
        m->next=NULL;

        a=sortList(a);
        b=sortList(b);

        ListNode* nhead=merge(a,b);
        return nhead;

        }
};

