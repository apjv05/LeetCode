class Solution {
public:
    int goodNodes(TreeNode* root) {
        int goodnodes = 0;
        dfs(root, root->val, goodnodes);
        return goodnodes;
    }

    void dfs(TreeNode* cur, int max, int& goodnodes) {
        if(cur == nullptr) return;

        if(cur->val >= max) goodnodes++;
        if(cur->val > max) max = cur->val;

        dfs(cur->left,max,goodnodes);
        dfs(cur->right,max,goodnodes);
    }
};