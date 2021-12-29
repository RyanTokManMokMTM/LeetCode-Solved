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
    unordered_map<int,int> maps;
    int index = 0;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i = 0;i<inorder.size();i++) maps[inorder[i]] = i;
        return getTree(preorder,inorder,0,preorder.size()-1);
    }
    
    TreeNode* getTree(vector<int>& preorder, vector<int>& inorder,int start,int end){
        if(start > end) return NULL;
        
        //according preorder to figure out child
        TreeNode* node = new TreeNode(preorder[index++]);
        if(start==end) return node;
        
        node->left = getTree(preorder,inorder,start,maps[node->val]-1);
        node->right = getTree(preorder,inorder,maps[node->val]+1,end);
        
        return node;
    }
};