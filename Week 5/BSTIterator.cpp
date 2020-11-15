class BSTIterator {
    stack<TreeNode*> s;
    
    void insert(TreeNode* root){
        while(root){
            s.push(root);
            root = root->left;  
        }
    }
public:
    BSTIterator(TreeNode* root) {
      insert(root);  
    }
    
    /** @return the next smallest number */
    int next() {
        TreeNode* curr = s.top(); 
        s.pop();
        insert(curr->right);
        return curr->val;
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !s.empty();
    }
};