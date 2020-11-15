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
    int height(TreeNode* root)
    {
        if(root==NULL)
        {
            return 0;
        }

        int leftChildHeight=height(root->left);
        int rightChildHeight=height(root->right);

        int h=max(leftChildHeight,rightChildHeight)+1;
        return h;
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==NULL)
        {
            return 0;
        }

        int op1=height(root->left)+height(root->right);
        //cout<<"op1 : "<<op1<<endl;
        int op2=diameterOfBinaryTree(root->left);
        //cout<<"op2 : "<<op2<<endl;
        int op3=diameterOfBinaryTree(root->right);
        //cout<<"op3 : "<<op3<<endl;

        int ans=max(op1,max(op2,op3));
        return ans;
    }
};