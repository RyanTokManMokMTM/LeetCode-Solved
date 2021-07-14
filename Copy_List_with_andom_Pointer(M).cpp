/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == NULL)
            return NULL;
        
        map<Node*,Node*> map; //A list node to B listNode
        
        Node* current = head;
        Node* copyList  = new Node(0); //just a dummy node
        Node* result = copyList;
        
        while(current!=NULL){
            Node* temp = new Node(current->val);//ceate a val node first
            map.insert(pair<Node*,Node*>(current,temp));//hashmap NodeA to NodeB
            copyList->next = temp;
            copyList = copyList->next;
            current = current->next;
        }
        
        copyList = result->next;
        current = head;
        
        while(current!=NULL){
            if(current->random != NULL){
                //find the addr with map
                if(map.find(current->random) != map.end()){
                    auto NodeAddr = map.find(current->random); //it must find random will linked to previous node
                    copyList->random = NodeAddr->second;
                }
            }

            copyList = copyList->next;
            current = current->next;
        }

        
        return result->next;
    }
};

//using the map here
//we can also use the hit A-A'-B-B'-C-C'...