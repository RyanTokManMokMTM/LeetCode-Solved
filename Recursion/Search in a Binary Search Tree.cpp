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
    TreeNode* searchBST(TreeNode* root, int val) {
        if(root == nullptr) return root;
        
        //check val
        if(root->val > val){
            //go to left
            return searchBST(root->left,val); //
        }else if(root->val < val){
            return  searchBST(root->right,val);
        }else{
            return root;
        }
        // TreeNode* left = searchBST(root->left,val);
        // if(left!=nullptr && left->val == val) return left; 
        // TreeNode* right = searchBST(root->right,val);
        // if(right!=nullptr && right->val == val) return right; 

    }
};