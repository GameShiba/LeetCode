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
    int deepestLeavesSum(TreeNode* root) {
        int sum;
        queue<TreeNode*> queue;
        queue.push(root);
        while (!queue.empty()) {
            sum = 0;
            int queueSize = queue.size();
            while (queueSize--) {
                TreeNode* front = queue.front();
                queue.pop();
                sum += front->val;
                if (front->left != nullptr)
                    queue.push(front->left);
                if (front->right != nullptr)
                    queue.push(front->right);
            }
        }
        return sum;
    }
};