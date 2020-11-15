class Solution {
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        int sum=0;
        if(root==NULL)
            return sum;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* curr = q.front();
            q.pop();
            if(curr->val >= low && curr->val <=high){
                sum += curr->val;
            }
            if(curr->left!=NULL && curr->val>low)
                q.push(curr->left);
            if(curr->right!=NULL && curr->val<high)
                q.push(curr->right);
        }
        return sum;
    }
};
