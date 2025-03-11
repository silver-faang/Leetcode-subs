class Solution {
public:
    bool dfs(int nd,vector<int> & vis,vector<vector<int>> &adj,vector<int> & pathvis){
        vis[nd]=1;
        pathvis[nd]=1;
        for(auto itr: adj[nd]){
            if(!vis[itr])
             {if(dfs(itr,vis,adj,pathvis))
              return true;}
            else if(pathvis[itr]) return true; 
        }
        pathvis[nd]=0;
        return false;
    }
    bool canFinish(int n, vector<vector<int>>& pre) {
        vector<vector<int>> adj(n);
        for(auto i:pre){
            adj[i[1]].push_back(i[0]);
        }
        vector<int> pathvis(n,0);
        vector<int> vis(n,0);
        for(int i=0;i<n;i++){
            if(!vis[i])
             if(dfs(i,vis,adj,pathvis))
              return false;
        }
        return true;
    }
};