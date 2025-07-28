class Solution {
public:
    int maxDepth(TreeNode* root) {
        int max = 0, depth = 0;
        dfs(root, depth, max);
        return max;
    }
    
    void dfs(TreeNode* node, int depth, int& max) {
        if(node == nullptr) {
            if(depth > max) max = depth;
            return;
        }
        dfs(node->left, depth + 1, max);
        dfs(node->right, depth + 1, max);
    }
};