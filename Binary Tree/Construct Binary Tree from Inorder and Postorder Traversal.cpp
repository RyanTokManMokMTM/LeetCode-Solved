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
    int LastIndex = 0; //used for postorder lastOne(current root is ?)
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        //store inorder value and its index to a map
        for(int i = 0;i<inorder.size();i++)  maps[inorder[i]] = i;
        
        //postOrder last index = postorder.size()-1;
        LastIndex = postorder.size()-1;
        return getTree(inorder, postorder,0,LastIndex);
    }
    
    TreeNode* getTree(vector<int>& inorder, vector<int>& postorder,int low,int height){
        if(low > height) return NULL;
            //there is no any element
        
        //create a treeNode(current Tree Root)
        TreeNode* node = new TreeNode(postorder[LastIndex--]); //start from lastIndex,     
        if(low == height) return root;
        //then get the root for index-1
        // int nextRootIndex = maps[node->val];
        //get current root right first and then left
        node->right = getTree(inorder, postorder,maps[node->val]+1,height);//right-hand size of current postorder in inorder from index+1 to height
        node->left = getTree(inorder, postorder,low,maps[node->val]-1);
        //left-hand size of current postorder in inorder from 0 to index -1
        
        return node;
    }
};