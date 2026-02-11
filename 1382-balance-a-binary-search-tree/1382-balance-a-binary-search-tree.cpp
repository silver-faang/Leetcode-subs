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
    void trav(TreeNode* root,vector<int>& in){
        if(!root) return;
        trav(root->left,in);
        in.push_back(root->val);
        trav(root->right,in);
    }
    TreeNode* create_bbst(vector<int>& in, int l, int r){
        if(l>r) return nullptr;
        int md=(l+r)>>1;
        TreeNode* lefttree=create_bbst(in,l,md-1);
        TreeNode* righttree=create_bbst(in,md+1,r);
        
        return new TreeNode(in[md],lefttree,righttree);
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector <int> inorder;
        trav(root,inorder);
        int n=inorder.size();
        return create_bbst(inorder, 0,n-1);
    }
};