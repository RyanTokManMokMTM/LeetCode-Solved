/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        Node* current = head,*child = NULL, *next = NULL;
        
        while(current != NULL){
            
            //check current has a child?
            if(current->child){
                if(current->next == NULL){
                    // just connect to child
                    current->next = current->child;
                    current->next->prev = current;
                    current->child = NULL;
                    continue;
                }
                
                next = current->next; //get next node of current list 
                current->next =current->child; //set next current node to next
                current->next->prev = current; //set next current previous to current
                current->child = NULL; //break current;
                
                child = current->next;
                while(child->next != NULL) //get tail of current child list and appen next to it
                    child = child->next;

                child->next=next;
                next->prev = child;        
            }
            current = current->next;
        }
        return head;
    }
};


//not only this solution
// also can apply DFS