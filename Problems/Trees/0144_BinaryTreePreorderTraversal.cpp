class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> output;
        dfs(root, output);
        return output;
    }
    void dfs(TreeNode* node, vector<int>& output) {
        if(node == nullptr) return;
        output.push_back(node->val);
        dfs(node->left, output);
        dfs(node->right, output);
    }
};