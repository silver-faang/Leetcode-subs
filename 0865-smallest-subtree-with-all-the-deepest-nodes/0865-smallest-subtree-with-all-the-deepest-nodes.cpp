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
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        if(!root) return nullptr;
        unordered_map<TreeNode*,TreeNode*>p;
        queue<TreeNode*> q;
        q.push(root);
        p[root]=nullptr;
        vector<TreeNode*> level;
        while(q.size()){
            int size=q.size();
            level.clear();
            for(int i=0;i<size;i++){
                TreeNode* nd=q.front();
                q.pop();
                level.push_back(nd);
                if(nd->left){
                    p[nd->left]=nd;
                    q.push(nd->left);
                }
                if(nd->right){
                    p[nd->right]=nd;
                    q.push(nd->right);
                }
            }
        }
        unordered_set<TreeNode*> deepest(level.begin(),level.end());
        while(deepest.size()>1){
            unordered_set<TreeNode*>next;
            for(auto nd:deepest){
                next.insert(p[nd]);
            }
            deepest=next;
        }
        return *deepest.begin();
    }
};