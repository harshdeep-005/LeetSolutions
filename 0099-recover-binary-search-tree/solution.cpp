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
    void foo(TreeNode* root, vector<TreeNode*>& arr) {
    if (!root) return;
    
    foo(root->left, arr);
    arr.push_back(root); 
    foo(root->right, arr);
}

void recoverTree(TreeNode* root) {
    vector<TreeNode*> arr;
    foo(root, arr);

    TreeNode* first = nullptr;
    TreeNode* second = nullptr;

    for (int i = 0; i < arr.size() - 1; i++) {
        if (arr[i]->val > arr[i + 1]->val) {
            if (!first) first = arr[i];  
            second = arr[i + 1];         
        }
    }

    if (first && second) swap(first->val, second->val);
}
};
