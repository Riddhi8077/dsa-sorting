#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

/* * TreeNode structure is already defined by LeetCode implicitly:
 * struct TreeNode {
 * int val;
 * TreeNode *left;
 * TreeNode *right;
 * ...
 * };
 */

class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*> nodeMap;
        unordered_set<int> childrenSet;

        for (const auto& desc : descriptions) {
            int parentVal = desc[0];
            int childVal = desc[1];
            int isLeft = desc[2];

            if (nodeMap.find(parentVal) == nodeMap.end()) {
                nodeMap[parentVal] = new TreeNode(parentVal);
            }
            if (nodeMap.find(childVal) == nodeMap.end()) {
                nodeMap[childVal] = new TreeNode(childVal);
            }

            if (isLeft == 1) {
                nodeMap[parentVal]->left = nodeMap[childVal];
            } else {
                nodeMap[parentVal]->right = nodeMap[childVal];
            }

            childrenSet.insert(childVal);
        }

        TreeNode* root = nullptr;
        for (const auto& desc : descriptions) {
            int parentVal = desc[0];
            if (childrenSet.find(parentVal) == childrenSet.end()) {
                root = nodeMap[parentVal];
                break;
            }
        }

        return root;
    }
};
