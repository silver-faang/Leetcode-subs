class Solution {
public:
    bool dfs(int nd, vector<int> & vis,vector<int> &pathvis, vector<int> & safe, vector<vector<int>> & graph){
        vis[nd]=1;
        pathvis[nd]=1;
        for(auto it:graph[nd]){
            if(!vis[it])
             {
                if(dfs(it,vis,pathvis,safe,graph)){
                    safe[nd]=0;
                    return true;
                }
             }
             else if(pathvis[it])
             {
                safe[nd]=0;
                return true;
             }
        }
        safe[nd]=1;
        pathvis[nd]=0;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> vis(n,0), pathvis(n,0),safe(n,0);
        for(int i=0;i<n;i++){
            if(!vis[i])
             dfs(i,vis,pathvis,safe,graph);
        }
        vector<int> ans;
        for(int i=0;i<n;i++)
         if(safe[i]==1) ans.push_back(i);
        return ans; 
    }
};