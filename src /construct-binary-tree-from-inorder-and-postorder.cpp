#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    unordered_map<int, int> inorderIndex;
    int postIndex;

    TreeNode* build(vector<int>& postorder, int left, int right) {
        if (left > right) return nullptr;

        int rootVal = postorder[postIndex--];
        TreeNode* root = new TreeNode(rootVal);

        int index = inorderIndex[rootVal];

        root->right = build(postorder, index + 1, right);
        root->left = build(postorder, left, index - 1);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        postIndex = n - 1;

        for (int i = 0; i < n; i++) {
            inorderIndex[inorder[i]] = i;
        }

        return build(postorder, 0, n - 1);
    }
};
