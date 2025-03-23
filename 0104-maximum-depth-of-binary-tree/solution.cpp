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
    void foo(TreeNode* root, int n, int &maxi){
        if(root==nullptr)return;
        maxi= max(maxi,n);
        foo(root->left, n+1, maxi);
        foo(root->right, n+1, maxi);

    }
    int maxDepth(TreeNode* root) {
        int n=1, maxi=0;
        if(root==nullptr)return 0;
        foo(root, n, maxi);
        return maxi;
    }
};
