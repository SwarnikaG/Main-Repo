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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* current = head; 
        ListNode* coming; 

        if (current == NULL || current->next == NULL) 
        return head; 
 
        while (current->next != NULL) 
        { 
            if (current->val == current->next->val) 
            {       
                coming = current->next->next; 
                //free(current->next); 
                current->next = coming; 
            } 
            else 
            { 
                current = current->next; 
            } 
        } 
        return head;
    }
};