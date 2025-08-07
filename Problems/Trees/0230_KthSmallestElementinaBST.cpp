int kthSmallest(TreeNode* root, int k) {
    vector<int> nums;
    dfs(root, nums);
    return nums[k - 1];
}

void dfs(TreeNode* node, vector<int>& nums) {
    if(!node) return;
    dfs(node->left, nums);
    nums.push_back(node->val);
    dfs(node->right, nums);
}
//in order traversal works here because it keeps the vector sorted