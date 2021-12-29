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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        recursivePeorder(root,result);
        return result;
    }
    
    void recursivePeorder(TreeNode* root,vector<int> &vector){
        if(root == NULL)
            return;
        vector.push_back(root->val);
        recursivePeorder(root->left,vector);
        recursivePeorder(root->right,vector);
        
        
        return;
    }
};