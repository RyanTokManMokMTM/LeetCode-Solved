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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        recursivePostOrder(root,result);
        return result;
    }
    
    void recursivePostOrder(TreeNode* root,vector<int> &v){
        if(root == NULL)
            return;
        
        //LRV
        recursivePostOrder(root->left,v);
        recursivePostOrder(root->right,v);
        v.push_back(root->val);
        
        return;
    }
};