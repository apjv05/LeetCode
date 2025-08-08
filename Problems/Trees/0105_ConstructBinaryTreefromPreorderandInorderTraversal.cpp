int pre_idx = 0;
unordered_map<int, int> indices;

TreeNode* dfs(vector<int>& preorder, int l, int r) {
    if (l > r) return nullptr;

    int root_val = preorder[pre_idx++];
    TreeNode* root = new TreeNode(root_val);
    
    int mid = indices[root_val];
    root->left = dfs(preorder, l, mid - 1);
    root->right = dfs(preorder, mid + 1, r);

    return root;
}

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    for (int i = 0; i < inorder.size(); ++i) {
        indices.insert({inorder[i], i});
    }
    return dfs(preorder, 0, inorder.size() - 1);
}