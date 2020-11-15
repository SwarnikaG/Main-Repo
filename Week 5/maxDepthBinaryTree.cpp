class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == NULL )
            return NULL;
        return (max(maxDepth(root->left),maxDepth(root->right))+1);
    }
};