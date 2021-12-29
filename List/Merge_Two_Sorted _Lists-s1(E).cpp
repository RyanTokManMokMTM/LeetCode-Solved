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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1 == NULL && l2 == NULL)
            return NULL;
            
        if(l1 != NULL  && l2 == NULL)
            return l1;
        
        if(l2 != NULL  && l1 == NULL)
            return l2;
        
        printf("test");
        
        ListNode* preB = NULL,*currA = l1,*currB = l2;
        ListNode* NextA =NULL,*NextB = NULL;
        ListNode*lastB = NULL;
        ListNode*temp = currB;
        //we add l1 to l2
        while(currA != NULL && currB != NULL){ //either one is NULL
            //there 3 case;
            // 11 > l2  l2 > l1 l1=l2
            if(currB->next == NULL)
                lastB=currB;
            
            if(currA->val == currB->val){
               
                NextA = currA->next;
                NextB = currB->next;
                
                currA->next = NULL;
                currA->next = NextB;
                
                currB->next = currA;
                preB = currA;
 

                currA = NextA;
                currB = NextB;
            }else if(currA->val < currB->val){
                    NextA = currA->next;
                    currA->next = NULL;
                    currA->next = currB;
                    if(preB != NULL){
                        //This case ,we suppose all List A element will be smaller than list B
                        preB->next= currA;
                       
                    }else{
                        l2 = currA;
                    }
                    preB = currA;
                    currA = NextA;
                    
            }
            else{
                preB = currB;
                currB = currB->next;

            }
        }
        
        if(currA != NULL){
            if(lastB->next != NULL){
                lastB->next->next = currA;
                
            }
            else{
                 lastB->next = currA;
                    
            }
        }
        return l2;
    }
};

//iteration