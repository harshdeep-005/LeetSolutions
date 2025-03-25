/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool foo(TreeNode* root, vector<TreeNode*>& arr, TreeNode* x) {
    if (root == nullptr) return false;  

    arr.push_back(root);  

    if (root == x) return true;  

    
    if (foo(root->left, arr, x) || foo(root->right, arr, x))
        return true;

    arr.pop_back();  
    return false;
}


    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*>ar1,ar2;
        bool x=foo(root, ar1, p), y=foo(root, ar2, q);
        int i = 0;
        while (i < ar1.size() && i < ar2.size() && ar1[i] == ar2[i]) {
            i++;
        }
        cout << ar1[i - 1]->val;  
        return ar1[i - 1];  

    }
};
