vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> levels;
    if(root == nullptr) return levels;

    queue<TreeNode*> q;
    q.push(root);

    while(!q.empty()) {
        vector<int> level;
        int size = q.size();

        for(int i = 0; i < size; i++) {
            TreeNode* node = q.front();
            q.pop();
            if(node) {
                level.push_back(node->val);
                q.push(node->left);
                q.push(node->right);
            }
        }
        if(!level.empty()) levels.push_back(level);
    }
    return levels;
}