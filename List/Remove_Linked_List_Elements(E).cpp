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
    ListNode* removeElements(ListNode* head, int val) {
        if(head==NULL)
            return NULL;
        
        ListNode* current = head;
        ListNode* previous = NULL;
        ListNode* next = NULL;
        //Space time O(1)=>only 3 pointer
        //Time: O(n) need to loop over the list to figure out
        while(current!=NULL){
            next = current->next;
            if(current->val == val){
                previous == NULL ?  head = next:previous->next = next;
                // if(previous == NULL){
                //     //current is the firstNode of the list;
                //     //just remove
                //     delete current; 
                //     head = next; //first one is removed need to move the head
                // }else{
                //     previous->next = next;
                //     delete current;
                // }
                delete current;
            }else{
                previous = current;
            }
            current=next;
            
        }
        return head;
        
    }
};

//Using a loop
//better code
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
    ListNode* removeElements(ListNode* head, int val) {
        if(head==NULL)
            return NULL;
        
        ListNode* current = head;
        ListNode* previous = NULL;
        ListNode* next = NULL;
        //Space time O(1)=>only 3 pointer
        //Time: O(n) need to loop over the list to figure out
        while(current!=NULL){
            next = current->next;
            if(current->val == val){
                previous == NULL ?  head = next:previous->next = next;
                delete current;
            }else{
                previous = current;
            }
            current=next;
            
        }
        return head;
        
    }
};