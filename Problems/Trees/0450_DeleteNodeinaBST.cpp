//delete the node by changing its value to the value of the right child
TreeNode* deleteNode(TreeNode* root, int key) {
    if(!root) return root;

    if(key < root->val) root->left = deleteNode(root->left, key);
    else if (key > root->val) root->right = deleteNode(root->right, key);
    else {
        if(!root->left) return root->right;
        if(!root->right) return root->left;

        //find min from right subtree
        TreeNode* cur = root->right;
        while(cur->left) cur = cur->left;

        //change value and hangle its children
        root->val = cur->val;
        root->right = deleteNode(root->right, root->val);
    }
    return root;
}