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
        int a=foo(root->left, maxi), b=foo(root->right, maxi);
        maxi= max(a+b,maxi);
        cout<<maxi<<endl;
        return max(a,b)+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int z, maxi=0;
        z=foo(root, maxi);
        return maxi;
    }
};
