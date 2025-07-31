TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (!root || !p || !q) return nullptr;
    
    int bigval = max(p->val, q->val);
    int smallval = min(p->val, q->val);

    if(bigval < root->val) return lowestCommonAncestor(root->left, p, q);
    else if(smallval > root->val) return lowestCommonAncestor(root->right, p, q);
    else return root;
}