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
    ListNode* rotateRight(ListNode* head, int k) {
    //get the length first
        if(head == NULL)
            return NULL;
        
        //get the length frist
        int length = 0;
        ListNode* cur = head;
        while(cur != NULL){
            cur = cur->next;
            length++;
        }
        k = k%length;

        if(k == 0) return head;
        
        //calculate the k position
        cur = head;
        ListNode* pre = cur;
        ListNode* result = NULL;
        k = length - k;
        
        while(k>0){
            pre=cur;
            cur = cur->next;
            k--;
        }
        
        //cur is head
        //pre is last
        
        pre->next = NULL;
        result = cur;
        
        //connect last node to head
        while(cur->next != NULL) cur = cur->next;
        
        cur->next =head;

        return result;
    }
};
//calculate where to break the list


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
    ListNode* rotateRight(ListNode* head, int k) {
    //get the length first
        if(head == NULL)
            return NULL;
        
        ListNode* cur = head;
        ListNode* last = NULL;
        int length = 0;
        while(cur != NULL){
            if(cur->next == NULL) last = cur;
            cur = cur->next;
            length++;
        }
        last->next = head;
        
        k = k%length;
        k = length-k-1; //get loop time to break;

        cur=head;
        while(k>0){
            printf("%d ",cur->val);
            cur=cur->next;
            k--;
        }
        printf("%d ",cur->val);
        head = cur->next;
        cur->next = NULL;
        
        return head;
    }
};
//same solution just a recap