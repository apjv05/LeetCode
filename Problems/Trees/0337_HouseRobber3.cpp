unordered_map<TreeNode*, int> map;

int rob(TreeNode* root) {
    map.insert({nullptr, 0});
    return dfs(root);
}

int dfs(TreeNode* node) {
    if(map.find(node) != map.end()) return map[node];

    int money = node->val;

    //find current route max
    if(node->left) money += rob(node->left->left) + rob(node->left->right);
    if(node->right) money += rob(node->right->right) + rob(node->right->left);

    //find alt route max
    money = max(money, rob(node->left) + rob(node->right));
    map[node] = money;
    return money;
}