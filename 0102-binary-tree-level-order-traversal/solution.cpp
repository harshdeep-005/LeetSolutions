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
    // void foo(TreeNode* root,priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>& pq, int n){
    //     if (root == nullptr) return; 
    //     pq.push({n, root->val});
    //     foo(root->left, pq,n+1);
    //     foo(root->right, pq,n+1);
    // }
    // vector<vector<int>> levelOrder(TreeNode* root) {
    //     vector<vector<int>> arr;
    //     priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    //     int n=0, m=0;
    //     foo(root,pq,n);
    //     while (!pq.empty()) {
    //         vector<int>ar;
    //         do{
    //         ar.push_back(value);
    //         auto [key, value] = pq.top();
    //         pq.pop();
    //         m=key
    //         }while(key==m)
    //         arr.push_back(ar);
    //         ar.clear();
    //         m=key
    //     }

    //     return {{3},{9,20},{7,15}};
    // }
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        if(root==NULL)return ans;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int s=q.size();
            vector<int>v;
            for(int i=0;i<s;i++){
                TreeNode *node=q.front();
                q.pop();
                if(node->left!=NULL)q.push(node->left);
                if(node->right!=NULL)q.push(node->right);
                v.push_back(node->val);
            }
            ans.push_back(v);
        }
        return ans;
    }
};
