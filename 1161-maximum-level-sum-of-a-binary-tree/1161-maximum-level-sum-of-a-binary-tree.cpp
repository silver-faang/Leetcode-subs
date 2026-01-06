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
    vector<int> sum= {INT_MIN};
    void dfs(TreeNode * Nd,int l=1){
        if(Nd==NULL) return;
        if(sum.size()==l) sum.push_back(Nd->val);
        else sum[l]+=Nd->val;
        dfs(Nd->left,l+1);
        dfs(Nd->right,l+1);
    }
    int maxLevelSum(TreeNode* root) {
        dfs(root);
        return max_element(sum.begin(),sum.end())-sum.begin();
    }
};