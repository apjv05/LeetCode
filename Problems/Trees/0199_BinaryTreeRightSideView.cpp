vector<int> rightSideView(TreeNode* root) {
    vector<int> output;
    if (root == nullptr) return output;

    deque<TreeNode*> q;
    q.push_back(root);

    while (!q.empty()) {
        int levelSize = q.size();
        output.push_back(q.back()->val);

        for (int i = 0; i < levelSize; i++) {
            TreeNode* node = q.front();
            q.pop_front();
            if (node->left) q.push_back(node->left);
            if (node->right) q.push_back(node->right);
        }
    }
    return output;
}