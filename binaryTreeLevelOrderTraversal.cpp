//https://leetcode.com/problems/binary-tree-level-order-traversal/

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        vector<vector<int>> res;
        while(1){
            int size = q.size();//everytime find the size of the queue
            if(size==0)
                break;
            vector<int> level;
            // while queue is not empty
            while(size>0){
                // pick the front element from queue
                TreeNode* temp = q.front();
                q.pop();// pop the element too
                level.push_back(temp->val);
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