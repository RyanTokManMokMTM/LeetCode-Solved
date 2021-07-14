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
    ListNode *detectCycle(ListNode *head) {
        if(head == NULL || head->next == NULL)
            return NULL;
        
        ListNode*slower = head;
        ListNode*faster = head;
        bool isCycle = false; //check is loop or not
        while(faster != NULL && faster->next != NULL){ 
            faster = faster->next->next;
            slower = slower->next;
            if(slower == faster){
                isCycle = true;
                printf("%d",slower->val);
                break;        
            }

            
        }
        
        //we check is cycle already ,and using loop to find out the index/addr of this node
        if(isCycle){
            ListNode* finder = head;
            while(finder != slower){
                finder = finder->next;
                slower = slower->next;
            }
            return finder;
        }
        return NULL;
            
            
    }
};

/*
    STEP 1: using runner Method to check is cycle
    STEP 2: using another loop to find the connected node

*/