/* 平衡二叉树的定义：
空节点是平衡二叉树；
任何节点左右子树的高度差小于1

实现点：
1、求树的高度；
2、递归
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if (root == NULL) {
            return true;
        }
        if (abs(height(root->left) - height(root->right)) > 1) {
            return false;
        }
        return isBalanced(root->left) && isBalanced(root->right);
    }
    int height(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        return 1+max(height(root->left), height(root->right));
    }
};