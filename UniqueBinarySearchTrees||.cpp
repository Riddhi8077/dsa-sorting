class Solution {
public:
    vector<TreeNode*> build(int start, int end) {
        if (start > end) return {nullptr};

        vector<TreeNode*> trees;

        for (int i = start; i <= end; i++) {
            auto leftTrees = build(start, i - 1);
            auto rightTrees = build(i + 1, end);

            for (auto left : leftTrees) {
                for (auto right : rightTrees) {
                    TreeNode* root = new TreeNode(i);
                    root->left = left;
                    root->right = right;
                    trees.push_back(root);
                }
            }
        }

        return trees;
    }

    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) return {};
        return build(1, n);
    }
};
