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

    int kthSmallest(TreeNode* root, int k) {
        int count = 0;
        return traversal(root, k, &count)->val;
    }
    
private:

    TreeNode* traversal(TreeNode *root, int k, int *count){
        if(root==NULL) return NULL;
        TreeNode *left;
        //cout<<"count "<<*count<<endl;
        left = traversal(root->left, k, count);
        if(*count == k) {
            //cout<<"first if"<<endl;
            //cout<<left->val<<endl;
            return left;
        }
        (*count)++;
        //cout<<"count++ "<<*count<<endl;
        if(*count == k) {
            //cout<<"second if"<<endl;
            //cout<<root->val<<endl;
            return root;
        }
        //cout<<"last return :"<<endl;
        //cout<<root->val<<" "<<k<<" "<<*count<<endl;
        return traversal(root->right, k, count);
    }
};