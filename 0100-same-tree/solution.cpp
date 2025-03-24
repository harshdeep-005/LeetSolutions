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
    void foo(TreeNode* p, TreeNode* q, bool &res){
        if(((p==nullptr)&&(q!=nullptr))||((p!=nullptr)&&(q==nullptr))){
            res=false;
            return;
        }
        if(((p==nullptr)&&(q==nullptr)))return;
        foo(p->left,q->left,res);
        foo(p->right,q->right,res);
        if(p->val!=q->val)res=false;
        return;
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        bool res=true;
        foo(p,q,res);
        return res;
    }
};
