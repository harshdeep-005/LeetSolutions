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
        if (!root) return;
        
        foo(root->left, arr);
        arr.push_back(root->val); 
        foo(root->right, arr);
    }
    bool findTarget(TreeNode* root, int k) {
        vector<int> arr;
        foo(root, arr);
        int m=0, n=arr.size()-1;
        while(m<n){
            if(arr[m]+arr[n]==k)return true;
            if(arr[m]+arr[n]<k)m++;
            else n--;
        }
        return false;
    }
};
