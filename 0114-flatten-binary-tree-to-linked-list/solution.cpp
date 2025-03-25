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
    void foo(TreeNode* root, vector<int>& arr) {
        if (root == nullptr) return; 
        arr.push_back(root->val); 
        foo(root->left, arr);     
        foo(root->right, arr);  
    }

    void foo1(TreeNode* root, vector<int>& arr, int i) {
        if (i >= arr.size()) {
            root = nullptr;
            return;
        }
        root->val = arr[i];  
        root->left = nullptr;  
        
        if (i + 1 < arr.size()) {
            root->right = new TreeNode(0);  
            foo1(root->right, arr, i + 1);  
        } 
        else {
            root->right = nullptr;
        }
    }

    void flatten(TreeNode* root) {
        if (!root) return;
        
        vector<int> arr;
        foo(root, arr);  
        foo1(root, arr, 0);  
    }
};

