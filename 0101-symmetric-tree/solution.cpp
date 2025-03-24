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
    void foo1(TreeNode* root, vector<int>& arr) {
        if (root == nullptr) {
            arr.push_back(INT_MIN); 
            return;
        } 

        arr.push_back(root->val); 
        foo1(root->left, arr);     
        foo1(root->right, arr);  
    }

    void foo2(TreeNode* root, vector<int>& arr) {
        if (root == nullptr) {
            arr.push_back(INT_MIN);
            return;
        }  

        arr.push_back(root->val); 
        foo2(root->right, arr);  
        foo2(root->left, arr);     
    }

    bool isSymmetric(TreeNode* root) {
        if (!root) return true; 

        vector<int> ar1, ar2;
        foo1(root->left, ar1);
        foo2(root->right, ar2);

        return ar1 == ar2; 
    }
};

