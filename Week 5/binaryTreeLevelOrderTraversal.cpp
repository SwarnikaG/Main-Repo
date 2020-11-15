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
        vector<vector<int>> res;
        if(root==NULL)
            return res;
        queue<TreeNode*> q;
        q.push(root);
        
        while(1){
            int size = q.size();//everytime find the size of the queue
            if(size==0)
                break;
            vector<int> level;
            // while queue is not empty
            while(size>0){
                // pick the front element from queue
                TreeNode* temp = q.front();                
                level.push_back(temp->val);
                q.pop();// pop the element too
                // if left/right child exists push it into queue
                if(temp->left!=NULL)
                    q.push(temp->left);
                if(temp->right!=NULL)
                    q.push(temp->right);
                
                size--;
            }
            res.push_back(level);
        }
        return res;
    }
};

