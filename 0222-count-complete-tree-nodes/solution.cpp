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
    void foo(TreeNode* root, int &x){
        if(root==nullptr)return;
        x++;
        foo(root->left, x);
        foo(root->right, x);
        return;
    }
    int countNodes(TreeNode* root) {
        int x=0;
        foo(root,x);
        return x;
    }
};
