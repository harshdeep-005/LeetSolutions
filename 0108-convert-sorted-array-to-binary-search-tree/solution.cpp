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
    TreeNode* foo(vector<int>& nums, int l, int r) {
        if(l>r)return nullptr;
        int m=l+(r-l)/2;
        TreeNode *head=new TreeNode (nums[m]);
        head->left=foo(nums,l,m-1);
        head->right=foo(nums,m+1,r);
        return head;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n=nums.size(),l=0,r=n-1;
        return foo(nums,l,r);
    }
};
