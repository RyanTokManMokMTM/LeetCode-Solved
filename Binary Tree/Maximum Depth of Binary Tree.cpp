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

    int maxDepth(TreeNode* root) {
        if(root == NULL) return 0;
        
        int left_depth = maxDepth(root->left);
        int right_depth = maxDepth(root->right);
        
        return max(left_depth,right_depth)+1; //at leaf max(0,0) +1  = 1,bottom up suppose right sub tree = 2,max(1,2)+1 = 3->depth = 3
    }
    
//     int findDepther(TreeNode* root,int depath){
//         if(root == NULL)
//             return depath;
        
//         int currentMaxDepath = depath;
        
//         if(root->left != NULL){
//             int temp = findDepther(root->left,depath+1);
//             currentMaxDepath = max(currentMaxDepath,temp); 
//         }
//         if(root->right != NULL){
//             int temp = findDepther(root->right,depath + 1);
//             currentMaxDepath = max(currentMaxDepath,temp);

//         }
        
//         return currentMaxDepath;
//     }
    
};