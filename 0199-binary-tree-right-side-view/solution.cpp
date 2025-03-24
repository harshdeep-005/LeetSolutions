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
    void foo(TreeNode* root, unordered_map<int,int>&map, int n){
        if(root==nullptr)return;
        map[n]=root->val;
        foo(root->left, map, n+1);
        foo(root->right, map, n+1);
        return;
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        unordered_map<int,int>map;
        foo(root, map, 0);
        int n=map.size();
        for(int i=0; i<n; i++){
            ans.push_back(map[i]);
        }
        return ans;
    }
};
