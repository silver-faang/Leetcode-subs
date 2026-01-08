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
 #define ll long long
class Solution {
public:
    ll md=1e9+7;
    ll ans=0;
     ll dfs(TreeNode* node){
            if(!node) return 0;
            node->val+=dfs(node->left)+dfs(node->right);
            return node->val;
        }
    int maxProduct(TreeNode* root) {
       ll total=dfs(root);
       queue<TreeNode*> q;
       q.push(root);
       while(q.size()){
        TreeNode * nd=q.front();
        q.pop();
        if(!nd) continue;
        ll cur=(total-nd->val)*nd->val;
        ans=max(ans,cur);
        if(nd->left) q.push(nd->left);
        if(nd->right) q.push(nd->right);
       }
       return ans%md;
    }
};