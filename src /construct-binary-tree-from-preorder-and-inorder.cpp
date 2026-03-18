#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    unordered_map<int, int> inorderIndex;
    int preIndex = 0;

    TreeNode* build(vector<int>& preorder, int left, int right) {
        if (left > right) return nullptr;

        int rootVal = preorder[preIndex++];
        TreeNode* root = new TreeNode(rootVal);

        int index = inorderIndex[rootVal];

        root->left = build(preorder, left, index - 1);
        root->right = build(preorder, index + 1, right);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for (int i = 0; i < inorder.size(); i++) {
            inorderIndex[inorder[i]] = i;
        }
        return build(preorder, 0, inorder.size() - 1);
    }
};
