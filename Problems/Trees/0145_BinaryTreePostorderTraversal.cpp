class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> output;
        dfs(root, output);
        return output;
    }

    void dfs(TreeNode* node, vector<int>& output) {
        if(node == nullptr) return;
        dfs(node->left, output);
        dfs(node->right, output);
        output.push_back(node->val);
    }
};