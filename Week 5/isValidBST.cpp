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
    bool isValidBST(TreeNode *root) {
                long long min = LLONG_MIN, max = LLONG_MAX;
                return isValidBST(root, min, max);
            }
    
    bool isValidBST(TreeNode *node, long long min, long long max){
        if(node == NULL)
            return true;
        if(node->val <= min || node->val >= max)
            return false;
        if(isValidBST(node->left, min, node->val) &&
           isValidBST(node->right, node->val, max))
            return true;
        return true;
    }

};

