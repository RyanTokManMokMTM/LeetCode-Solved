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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    //TODO
    /*
    ADD : each node is between 0-9 at most 9+9 = 18 carry is 1
    loop over 2 list together and get carry
    and carry is between 0-1,if carry = 1 ,create a node with that carry and return
    */
        ListNode* resultList = new struct ListNode(0);//un used node
        ListNode* a = l1, *b = l2,*addRes = resultList;
        int carry = 0,sum = 0,numA=0,numB = 0;
        
        //TIME: O(M)/O(N) depend on which list is longest
        //need to loop over all elmemn
        
        //Space:O(M)/(ON) + 1
        while(a != NULL || b != NULL){
            numA = a != NULL ? a->val : 0; // if b = longest than a
            numB = b != NULL ? b->val : 0; // if a = longest than b
            
            sum = carry + numA + numB;
            // carry = sum / 10; //largest sum = 9+9+1(carry) = 19 ,carry between 0-1
            carry = sum > 9 ? 1 : 0;
            addRes->next = new struct ListNode(sum%10);
            addRes = addRes->next;
            if(a!=NULL) a = a->next;
            if(b!=NULL) b = b->next;
        }

        if(carry > 0)
            addRes->next = new struct ListNode(carry); //add carry at the end 
        
        return resultList->next;
    
    }
};

//using the adder sum carry