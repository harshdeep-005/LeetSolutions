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
    TreeNode* foo(vector<int>& preorder, int& preIndex, int inStart, int inEnd, unordered_map<int, int>& inorderMap) {
        if (inStart > inEnd) return nullptr;

        int rootVal = preorder[preIndex++];
        TreeNode* root = new TreeNode(rootVal);

        int inIndex = inorderMap[rootVal];

        root->left = foo(preorder, preIndex, inStart, inIndex - 1, inorderMap);
        root->right = foo(preorder, preIndex, inIndex + 1, inEnd, inorderMap);

        return root;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        unordered_map<int, int> inorderMap;
        vector<int> inorder(preorder.begin(), preorder.end());
        sort(inorder.begin(),inorder.end());
        for (int i = 0; i < inorder.size(); i++) {
            inorderMap[inorder[i]] = i;
        }

        int preIndex = 0;
        return foo(preorder, preIndex, 0, inorder.size() - 1, inorderMap);
    }
};
