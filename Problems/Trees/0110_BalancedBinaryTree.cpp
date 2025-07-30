class Solution {
public:
    bool isBalanced(TreeNode* root) {
        return dfs(root) != -1;
    }

    //use dfs to calculate the height of each sub tree then compare
    int dfs(TreeNode* node){
        if(!node) return 0;

        int left = dfs(node->left);
        int right = dfs(node->right);

        if(left == -1 || right == -1) return -1;
        if(abs(left - right) > 1) return -1;
        return max(left, right) + 1;
    }
};