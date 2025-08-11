TreeNode* removeLeafNodes(TreeNode* root, int target) {
    if(!root) return nullptr;

    //root->left/right updates the parent pointer
    //so it doesnt point to nothing
    root->left = removeLeafNodes(root->left, target);
    root->right = removeLeafNodes(root->right, target);
    if(!root->left && !root->right && root->val == target) return nullptr;
    return root;
}