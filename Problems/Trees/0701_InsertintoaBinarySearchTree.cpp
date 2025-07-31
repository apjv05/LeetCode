TreeNode* insertIntoBST(TreeNode* root, int val) {
    if (!root) return new TreeNode(val);
    
    TreeNode* cur = root;
    TreeNode* parent = cur;

    while(cur != nullptr) {
        parent = cur;
        if(val < cur->val) cur = cur->left;
        else if(val > cur->val) cur = cur->right;
    }
    if(val < parent->val) parent->left = new TreeNode(val);
    else parent->right = new TreeNode(val);
    return root;
}