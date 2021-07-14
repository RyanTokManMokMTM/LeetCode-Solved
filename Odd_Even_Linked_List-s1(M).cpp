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
        int index = 1; //why start at 1,because now head is start at index 3 3 == 1 == odd
        while(current != NULL){
            ListNode* next = current->next;
            current->next = NULL; //break the list
            if(index % 2 == 0){
                //even case
                even->next = current;
                even = even->next;    
            }
            else{
                odd->next = current;
                odd = odd->next;
            }
            index++;
            current = next;
        }
        even->next = NULL;
        odd->next = NULL;
        odd->next = evenHead;
        return head;
    }
};

//a suck method ,need need to module the indx