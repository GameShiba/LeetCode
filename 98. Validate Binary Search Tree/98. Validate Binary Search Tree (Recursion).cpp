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
public:
    bool BSTChecker(TreeNode* root, long long min, long long max) {
        if (root == nullptr) {
            return true;
        }
        if (root->val <= min || root->val >= max) {
            return false;
        }
        return BSTChecker(root->left, min, root->val) && BSTChecker(root->right, root->val, max);
    }

    bool isValidBST(TreeNode* root) {
        return BSTChecker(root, LONG_MIN, LONG_MAX);
    }
};