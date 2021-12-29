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

    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root == NULL)
            return false;
        
       if(!root->left && !root->right){
           if(targetSum == root->val){
               return true;
           }
            return false;
       }
    
        return hasPathSum(root->left,targetSum - root->val) || hasPathSum(root->right,targetSum - root->val);
    }
    
//     bool preOrdertraversal(TreeNode* root,int total,int target){
//         if(root == NULL)
//             return false;
        
//         total += root->val;
//         if(root->left == NULL && root->right==NULL){
//             if(total == target){
//                 return true;
//             }
//             else{
//                 return false;
//             }
//         }
        
        
//        return preOrdertraversal(root->left,total,target) || preOrdertraversal(root->right,total,target);
            

//     }
};