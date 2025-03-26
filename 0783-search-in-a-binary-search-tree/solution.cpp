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
    void foo(TreeNode* root, int valu, TreeNode* &x){
        if (root == nullptr) return;
        if (root->val == valu) {
            x = root;
            return;  
        }

        foo(root->left, valu, x);
        foo(root->right, valu, x);
    }
    TreeNode* searchBST(TreeNode* root, int val) {
        TreeNode* x=nullptr;
        foo(root, val, x);
        return x;
    }
};
