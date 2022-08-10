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
    TreeNode* BTree(vector<int>& nums, int left, int mid, int right) {
        TreeNode *root = new TreeNode(nums[mid]);
        int leftMid = (left + mid - 1) / 2 >= 0 ? (left + mid - 1) / 2 : 0;
        int rightMid = (mid + 1 + right) / 2 <= right ? (mid + 1 + right) / 2 : right;
        if (left <= leftMid && leftMid <= mid - 1) {
            root->left = BTree(nums, left, leftMid, mid - 1);
        }
        if (mid + 1 <= rightMid && rightMid <= right) {
            root->right = BTree(nums, mid + 1, rightMid, right);
        }
        return root;
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return BTree(nums, 0, (nums.size() - 1) / 2, nums.size() - 1);
    }
};