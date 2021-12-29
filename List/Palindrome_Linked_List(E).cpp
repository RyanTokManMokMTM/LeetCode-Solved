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
    bool isPalindrome(ListNode* head) {
        if(head == NULL || head->next == NULL)
            return true;
        
        ListNode* slow = head;
        ListNode* fast = head->next;
        
        
        while(fast!= NULL && fast->next !=NULL){
            if(fast->next->next == NULL){
                fast = fast->next;
            }
            else{
                 fast = fast->next->next;
            }
            slow = slow->next;
        }
        
        //slow is in the length /2
        //reverse the list from lenth/2 to last
        //and compare

        ListNode* reverseList = slow->next;
        ListNode* previous = NULL,*next = NULL;
        slow->next = NULL;
        slow = head;
        //reverse the list
        while(reverseList!=NULL){
            next = reverseList->next;
            reverseList->next = previous;
            
            previous=reverseList;
            reverseList = next;
        }

        while(slow != NULL && fast != NULL){
            if(slow->val != fast->val)
                return false;
            slow = slow->next;
            fast  = fast->next;
        }
        
        
        return true;
        
        
    }
};

//rever the list after mid length
//somthing 