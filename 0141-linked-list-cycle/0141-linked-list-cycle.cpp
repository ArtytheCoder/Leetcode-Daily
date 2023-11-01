class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head == NULL || head->next == NULL)
            return false;
        
          ListNode *first=head, *second=head;
        while(second && second->next){
            first= first->next;
            second= second->next->next;
            if(first == second)
                return true;
        }
        return false;
    }
};