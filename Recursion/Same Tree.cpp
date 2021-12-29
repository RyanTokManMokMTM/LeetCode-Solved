/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        //try iteration
        //base case
        if(q == nullptr && p == nullptr) return true;
        if(!(isSameNode(p,q))) return false;
            
        queue<TreeNode*> left; //store p node
        queue<TreeNode*> right; //store q node
        
        left.push(p); //put q node to q queue
        right.push(q); //put p node to p queue
        
        //(O(N)) time
        //O(N) space for 2 all node
        while(!(left.empty())){
            //talk out p and q to campare
            TreeNode* cNA = left.front();
            TreeNode* cNB = right.front();
            left.pop();
            right.pop();
            //check left node are same
            //and append
            if(!(isSameNode(cNA->left,cNB->left))) return false;
            if(cNA->left != nullptr){
                left.push(cNA->left);
                right.push(cNB->left);
            }

            
            //check right ndoe are same
            //and append
            if(!(isSameNode(cNA->right,cNB->right))) return false;
            if(cNA->right != nullptr){
                left.push(cNA->right);
                right.push(cNB->right);
            }
        }
        return true;
    }
    
    bool isSameNode(TreeNode* p, TreeNode* q){
        if(p == nullptr || q==nullptr) return q==p;
        return p->val == q->val ?  true :  false;
    }
};