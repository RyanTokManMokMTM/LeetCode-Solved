/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
       if(root == NULL)return root;
        
        queue<Node*> q;
        q.push(root);
        q.push(NULL);
        /*
        Using queue push root and a null 
        if current is not null push left child and right child
        if current is null(is end of current level) and push null and current is not q.empty
        

        */
        while(!q.empty()){
            Node* current = q.front();
            q.pop();
            
            if(current!=nullptr){
                current->next=q.front();
                if(current->left != NULL) q.push(current->left);
                if(current->right != NULL) q.push(current->right);
            }
            else if(current==nullptr && !q.empty()){
                q.push(NULL);
            }
        }

        return root;
    }
};