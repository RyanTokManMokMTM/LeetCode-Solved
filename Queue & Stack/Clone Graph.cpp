/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(node == nullptr) return node;
        
        stack<Node*> tempNode;
        vector<Node*> cloneTemp(101,NULL);
        tempNode.push(node);
        //vectore no need to copy??? 
        cloneTemp[node->val] = new Node(node->val,node->neighbors);
        while(!tempNode.empty()){
            //take the top of current node
            Node* current = tempNode.top();tempNode.pop();
            int currentVal = current->val;
                //current node has/have same neighbrs
                //creating a new list,and push the refernece to the stack
               // this code for checking current node neigbour
            for(int i = 0;i< current->neighbors.size();i++){
                int neigbourVal = current->neighbors[i]->val; // get current node num
                if(cloneTemp[neigbourVal] == nullptr){
                    //push to stack,need to loop through this next round
                    cloneTemp[neigbourVal] = new Node(neigbourVal,current->neighbors[i]->neighbors);
                    tempNode.push(current->neighbors[i]);
                }
                //our neigbourVal node is cloned，and set current value neighbors[i] to cloned node
                cloneTemp[current->val]->neighbors[i] = cloneTemp[neigbourVal];// get the reference of the node
            }


        }
        return cloneTemp[node->val];
    }
};