/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head == NULL)
            return false;
        
        ListNode* slower = head;
        ListNode* faster = head->next;
        
        while(slower!=faster){
            if(faster == NULL || faster->next == NULL) // if cycle ,fater will never equal to NULL
                return false;
            
            slower =slower->next; //slower is slower than faster no need to check
            faster = faster->next->next;
        }
        return true;
    }
};

//2 runner(slow and fast)