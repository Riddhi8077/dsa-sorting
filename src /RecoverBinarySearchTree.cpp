/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    TreeNode* first = nullptr;
    TreeNode* second = nullptr;
    TreeNode* prev = nullptr;

    void traverse(TreeNode* root) {
        if (root == nullptr) return;

        traverse(root->left);

        if (prev != nullptr && prev->val > root->val) {
            if (first == nullptr) {
                first = prev;
            }
            second = root;
        }
        
        prev = root;

        traverse(root->right);
    }

public:
    void recoverTree(TreeNode* root) {
        first = second = prev = nullptr;
        
        traverse(root);

        if (first != nullptr && second != nullptr) {
            swap(first->val, second->val);
        }
    }
};
