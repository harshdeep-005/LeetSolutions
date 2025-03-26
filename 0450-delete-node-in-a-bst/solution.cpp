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
    TreeNode* deleteNode(TreeNode* root, int key) {
        TreeNode* temp = root;
        TreeNode* parentRoot = nullptr;

        while (root && root->val != key) {
            parentRoot = root;
            if (key < root->val) root = root->left;
            else root = root->right;
        }

        if (!root) return temp;

        // Case 1:
        if (!root->left && !root->right) {
            if (!parentRoot) return nullptr; 
            if (parentRoot->left == root) parentRoot->left = nullptr;
            else parentRoot->right = nullptr;
            delete root;
            return temp;
        }

        // Case 2:
        if (!root->left || !root->right) {
            TreeNode* child = root->left ? root->left : root->right;
            if (!parentRoot) return child; 
            if (parentRoot->left == root) parentRoot->left = child;
            else parentRoot->right = child;
            delete root;
            return temp;
        }

        // Case 3:
        TreeNode* successor = root->right;
        TreeNode* successorParent = root;
        while (successor->left) {
            successorParent = successor;
            successor = successor->left;
        }

        root->val = successor->val;

        if (successorParent->left == successor) successorParent->left = successor->right;
        else successorParent->right = successor->right;

        delete successor;
        return temp;
    }
};

