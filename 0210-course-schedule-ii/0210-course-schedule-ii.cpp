class Solution {
public:
    bool dfs(int nd, vector<vector<int>> & adj, vector<int> & vis, vector<int> & tpsrt,vector<int>& pathvis){
        vis[nd]=1;
        pathvis[nd]=1;
        for(auto itr:adj[nd]){
            if(!vis[itr])
             {if (dfs(itr,adj,vis,tpsrt,pathvis)) return true;}
            else if(pathvis[itr]) return true; 
        }
        pathvis[nd]=0;
        tpsrt.push_back(nd);
        return false;
    }
    vector<int> findOrder(int n, vector<vector<int>>& pre) {
        vector<int> vis(n,0);
        vector<vector<int>> adj(n);
        for(auto itr:pre){
            adj[itr[1]].push_back(itr[0]);
        }
        vector<int> tpsrt;
        vector<int> pathvis(n,0);
        for(int i=0;i<n;i++)
         if(!vis[i])
          if (dfs(i,adj,vis,tpsrt,pathvis) )
           return {};
        reverse(tpsrt.begin(),tpsrt.end())  ;
        return tpsrt;  
    }
};