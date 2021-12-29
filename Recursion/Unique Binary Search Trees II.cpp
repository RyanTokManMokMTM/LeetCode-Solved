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
    /*
    TODO HERE
    1.we need to check all the possible tree for each root
    2.In each root determine the left tree and right tree
    3.Back to Step 1
    4.append the the tree
    */
    
    /*
    EXAMPLE 1 - 3
    current 2 ；here with 2 tree
    left :
    */
    vector<TreeNode*> generateTrees(int n) {
        //total23
        return generateSubTrees(1,n);
    }
    
    vector<TreeNode*> generateSubTrees(int x,int y) {
        //[x,y]
        vector<TreeNode*> list;
        if(x > y) return {nullptr};
        
        for(int i = x;i<=y;i++){
            //get the left tree
            //left must be x to i-1.It can't be greater than  current i(BST)
            vector<TreeNode*> left = generateSubTrees(x,i-1); 
             
            //get the right tree
            //right must be i+1 to y.It can't be less then current i (BST)
            vector<TreeNode*> right = generateSubTrees(i+1,y); 
            
            //here we got the left tree
            //beacuse it will return a list of treeNode
            for(auto lt : left){
                for(auto rt : right){
                    //create a new tree node with current index
                    TreeNode* root = new TreeNode(i);
                    root->left = lt;
                    root->right = rt;
                    list.push_back(root);
                }
            }
        }
        return list;
        
    }
};