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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // a bad solution!
       map<ListNode*,bool> exist;
        
        while(headA != NULL){
            exist.insert(pair<ListNode*,bool>(headA,true));
            headA = headA->next;
        }
        
        while(headB != NULL){
           if(exist.find(headB) != exist.end())
               return headB;
            headB = headB->next;
        }
        return NULL;
    }
};

//storing the addr to map