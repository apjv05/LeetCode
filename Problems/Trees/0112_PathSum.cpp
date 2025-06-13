bool hasPathSum(TreeNode* root, int targetSum) {
    //if empty return false
    if(!root) return false;
    
    //if the current node is a leaf, check if our current sum
    //is equal to our target sum
    if(!root->left && !root->right) return targetSum == root->val;
    
    //recursivly checks for a valid path in the left and right subtrees
    bool left_sum = hasPathSum(root->left, targetSum - root->val);
    bool right_sum = hasPathSum(root->right, targetSum - root->val);
    
    return left_sum || right_sum;
}