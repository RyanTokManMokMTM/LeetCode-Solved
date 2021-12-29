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
    ListNode* oddEvenList(ListNode* head) {
        //define 3pointer and 1 var for isOdd or even
        if(head == NULL || head->next == NULL)
            return head;

        ListNode*odd = NULL;
        ListNode*even = NULL;
        ListNode*current = head->next->next;
        ListNode* evenHead = head->next; //it must start at index 2nd 2/2 == 0 ->even index
        even = evenHead;
        odd = head;
        
        while(even != NULL && even->next != NULL){
            odd->next = even->next;
            odd = odd->next;
            
            even->next = odd->next;
            even = even->next;
        }
        
        odd->next = evenHead;
        return head;
    }
};

//using 2 pointer odd and even