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
    ListNode*lastNode = NULL;
    int NodeSize = 0;
    ListNode* reverseList(ListNode* head) {
        //if current or current->next is null return current
        //else 

        
        if(head==NULL || head->next == NULL){
            lastNode = head;
            return head;
        }
    
        NodeSize++;
        
        ListNode* current = reverseList(head->next);
        NodeSize --;
        current->next = head;
        head->next = NULL;
        if (NodeSize==0)
            return lastNode;
        
        return head;
        
       
    }
};

//using recursive