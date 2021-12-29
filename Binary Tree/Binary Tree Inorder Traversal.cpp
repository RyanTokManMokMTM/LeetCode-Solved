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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        recursiveInorder(root,result);
        return result;
        
    }
    
    void recursiveInorder(TreeNode* root,vector<int> &v){
        if(root == NULL)
            return;
        
        //LVR
        recursiveInorder(root->left,v);
        v.push_back(root->val);
        recursiveInorder(root->right,v);
        
        return;
    }
};