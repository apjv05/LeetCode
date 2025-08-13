string serialize(TreeNode* root) {
    if (!root) return "null";

    string output;
    queue<TreeNode*> queue;
    queue.push(root);

    while (!queue.empty()) {
        TreeNode* node = queue.front();
        queue.pop();
        if (!node) output += "null,";
        else {
            output += to_string(node->val) + ",";
            queue.push(node->left);
            queue.push(node->right);
        }
    }
    return output;
}

// Decodes your encoded data to tree.
TreeNode* deserialize(string data) {
    stringstream ss(data);
    string val;
    getline(ss, val, ',');
    if (val == "null") return nullptr;
    TreeNode* root = new TreeNode(stoi(val));
    queue<TreeNode*> queue;
    queue.push(root);

    while (getline(ss, val, ',')) {
        TreeNode* node = queue.front();
        queue.pop();
        if (val != "null") {
            node->left = new TreeNode(stoi(val));
            queue.push(node->left);
        }
        getline(ss, val, ',');
        if (val != "null") {
            node->right = new TreeNode(stoi(val));
            queue.push(node->right);
        }
    }
    return root;
}