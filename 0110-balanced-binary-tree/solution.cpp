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
    int foo(TreeNode* root, bool &x){
        if(root==nullptr)return 0;
        int a=foo(root->left, x), b=foo(root->right, x);
        if(abs(a-b)>1)x=false;
        return max(a,b)+1;
    }
    bool isBalanced(TreeNode* root) {
        bool x=true;
        int z= foo(root, x);
        return x;
    }
};
