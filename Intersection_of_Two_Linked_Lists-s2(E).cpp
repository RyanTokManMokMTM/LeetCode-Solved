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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
      //now we need to calculate the size of both list
        
        int countA=0, countB=0;
        ListNode *A  = headA,*B = headB;
        int total = 0;
        
        //calculate A first
        while(A != NULL){
            countA++;
            A = A->next;
        }
        
        while(B != NULL){
            countB++;
            B = B->next;
        }
        
        //now check which list is longer;
        
        total = countB - countA;
        
        if(countB - countA >=0){
            //in this case B is longer than A at least 1 node;
            
            B = headB;
            A = headA;
            total = countB - countA;
            
            //move forware B = to let A and B have a same length
            
            while(total >0){
                total--;
                B = B->next;
            }
            
            while(A != B){
                A = A->next;
                B = B->next;
            }
            
            return A;
                
        }
        else if(countA - countB >=0){
            B = headB;
            A = headA;
            total = countA - countB;
            
            //move forware B = to let A and B have a same length
            
            while(total >0){
                total--;
                A = A->next;
            }
            
            while(A != B){
                A = A->next;
                B = B->next;
            }
            
            return A;
        }
        return NULL;
    
    }
};

//2 list have same node are same
//check which list longer
//move the longer list to make them have same length
//compare the addr to figure out what node is the first node