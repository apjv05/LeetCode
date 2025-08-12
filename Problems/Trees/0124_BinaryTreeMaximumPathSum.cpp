int maxPathSum(TreeNode* root) {
    int sum = root->val;
    dfs(root, sum);
    return sum;
}

int dfs(TreeNode* node, int& sum) {
    if(!node) return 0;

    //find max for left and right subtrees
    //skip any negative nodes w/ the "0"s
    int leftmax = max(dfs(node->left, sum), 0);
    int rightmax = max(dfs(node->right, sum), 0);

    //find new max and update it
    sum = max(sum, node->val + leftmax + rightmax);

    //return max path
    return node->val + max(leftmax, rightmax);
}