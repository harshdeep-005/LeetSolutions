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
    int foo(TreeNode* root, int &maxi){
        if(root==nullptr)return 0;
        int a=max(0,foo(root->left, maxi)), b=max(0,foo(root->right, maxi));
        
        maxi= max(a+b+root->val,maxi);
        return root->val+max(a,b);
    }
    int maxPathSum(TreeNode* root) {
        int maxi=-1000, x=foo(root,maxi);
        return maxi;
    }
};
