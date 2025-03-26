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
    TreeNode* foo(vector<int>& postorder, int& postIndex, int inStart, int inEnd, unordered_map<int, int>& inorderMap) {
        if (inStart > inEnd) return nullptr;

        int rootVal = postorder[postIndex--];  
        TreeNode* root = new TreeNode(rootVal);

        int inIndex = inorderMap[rootVal];
        
        root->right = foo(postorder, postIndex, inIndex + 1, inEnd, inorderMap);
        root->left = foo(postorder, postIndex, inStart, inIndex - 1, inorderMap);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> inorderMap;
        for (int i = 0; i < inorder.size(); i++) {
            inorderMap[inorder[i]] = i;
        }

        int postIndex = postorder.size() - 1; 
        return foo(postorder, postIndex, 0, inorder.size() - 1, inorderMap);
    }
};
