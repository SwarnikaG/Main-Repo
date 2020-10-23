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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* head = NULL;
        if(l1 == NULL && l2 == NULL)
            return NULL;
        else{ 
            if(l1 == NULL)
            return l2;
        else if(l2 == NULL)
            return l1;
        }
        //decide from which of the two list head should be made
        if(l1->val < l2->val){
            head = l1;
            l1 = l1->next;
        }
        else{
            head = l2;
             l2 = l2->next;
            }
        // created Temp , for traversal in the newly created linked list
		//as we have to add new element into it and hence traverse it forward.
		//Cant do that with head because we have to return head 
		//at the end as a starting point of the new linked list(Final linked list)
      ListNode*temp = head;
        
        while(l1 && l2){
            if(l1->val < l2->val){
				   temp->next = l1;//Notice , here we are not creating a new node and then assigning value to it ....
//instead we are just pointing the new lists current pointer
// to the list's node which is having a lesser value according to the condition 
                temp = temp->next;
                l1 = l1->next;
            }
           else{
               temp->next = l2;
               temp = temp->next;
               l2 = l2->next;      
            }
        }
        
        if(l1!=NULL)
            temp->next = l1;
        else
            temp->next = l2;
        
        return head;
    }
};