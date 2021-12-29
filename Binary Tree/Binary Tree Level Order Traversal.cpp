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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;//O(N+N/2+1)
        if(root == NULL)
            return result;
        
        queue<TreeNode*> q;//O(N)
        q.push(root);
    
        while(!q.empty()){ //O(N*n/2+1)
            int n = q.size();
            vector<int> temp;
            
           for(int i = 0;i<n;i++){
                TreeNode*current = q.front();//first node
                q.pop();
                
                temp.push_back(current->val);
                
                if(current->left != NULL)
                    q.push(current->left);
                if(current->right != NULL)
                    q.push(current->right);
            }
            
            result.push_back(temp);

                
        }
        return result;
        
        

    }
};