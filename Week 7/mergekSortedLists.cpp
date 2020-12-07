class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue< pair< int,ListNode* > , vector<pair< int,ListNode* > > , greater<pair< int,ListNode* > >> pq ; 
        
        ListNode dummy(INT_MIN); 
        ListNode *t = new ListNode() ; 
       
        t = &dummy; 
        for( auto x : lists )
        if(x)
            pq.push({x->val , x });
        
        while( !pq.empty() )
        {
           auto x = pq.top().second ;
           pq.pop();   
           t->next = x ; 
           t = t->next ;  
            
           if(x->next)
               pq.push({ x->next->val , x->next } ); 
        }
        
        return dummy.next ; 
    }
};