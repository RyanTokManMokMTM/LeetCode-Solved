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
    bool isBST = true;
    bool isValidBST(TreeNode* root) {
        //here we need to store the pre root
        //using inorder traversal
        bool isBST = true;
        TreeNode* pre = NULL;
        inOrderBST(root,pre,isBST);
        return isBST;
    }

   //using inorder and after Left visted and check Visted node then store the previous visit node(root) next visted right node
    void inOrderBST(TreeNode* &root, TreeNode* &pre,bool &isBST){
        if(root == NULL) return;
        
        //left node first
        inOrderBST(root->left,pre,isBST);
        if(pre !=nullptr && root->val <= pre->val){
            isBST = false;
            return;
        }
        pre = root;
        //right node later
        inOrderBST(root->right,pre,isBST);
        return;
    }
    

    
};