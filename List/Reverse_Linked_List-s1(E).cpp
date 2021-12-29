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
        if(head == NULL)
            return NULL;
        
        ListNode*pre = NULL;
        ListNode*current = head;
       ListNode tempNode;
        while(current!=NULL){
            tempNode = *current->next; //save current as copy ,we can't change the next pointer
            current = &tempNode;
            printf("%d",current->val);
        }
        
        return current;
    }
};

// iteration solution