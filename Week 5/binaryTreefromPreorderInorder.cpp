/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        int n = inorder.size();
        unordered_map<int, int> in_map;
        //doing preprocessing and storing inorder traversal keys as key in hash table and indexes as values for linear time complexity
        for (int i = 0; i < n; ++i) {
            in_map[inorder[i]] = i;
        }
        
        return helper(preorder, in_map, 0, n-1, 0 , n-1);
    }
    
    TreeNode* helper(vector<int> &pre, unordered_map<int,int>& in_map, int ps, int pe, int is, int ie) {
        if (ps > pe || is > ie) {
            return NULL;
        }
        
        TreeNode* root = new TreeNode(pre[ps]);
        int id = in_map[pre[ps]];
        int l = id-is;
        root->left = helper(pre, in_map, ps+1, ps+l, is , is+l-1);
        root->right = helper(pre, in_map, ps+l+1, pe, is+l+1, ie);
        return root;
    }
};