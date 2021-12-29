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
    ListNode* swapPairs(ListNode* head) {
        //
        if(head == NULL ||head->next == NULL) return head;
        ListNode* returnHead = head->next;
        ListNode* pre = head;
        ListNode* cur,*nex;
        
        //current = current swaped head
        //O(N)
        while(pre != nullptr  && pre->next != nullptr){
            cur = pre->next; //previous node ->next
            nex = cur->next; //current node ->next
            cur->next = pre;
            if(nex == nullptr){
                pre->next = nullptr;
            }else if(nex->next == nullptr){
                pre->next = nex;
            }else{
                pre->next = nex->next;
            }
            pre = nex;
        }
        return returnHead;
    }
};