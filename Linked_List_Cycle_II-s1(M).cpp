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
        
        map<ListNode*,int> listNodeTemp;
        
        int index = 0;
        
        
        while(head != NULL){
            auto it = listNodeTemp.find(head);
            if(it != listNodeTemp.end()){
                return it->first;
            }
            listNodeTemp.insert({head,index});
            head = head->next;
            index ++;
        }
        return NULL;
            
            
    }
};

// a suck solution! using map