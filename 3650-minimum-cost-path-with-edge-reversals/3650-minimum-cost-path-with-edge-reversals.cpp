class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int,int>>> g(n);
        for(auto e: edges){
            g[e[0]].push_back({e[1],e[2]});
            g[e[1]].push_back({e[0],2*e[2]});
        }
        vector<int> d(n,INT_MAX);
        vector<bool> v(n,false);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        d[0]=0;
        pq.push({0,0});
        while(pq.size()){
            int u=pq.top().second;
            int d1=pq.top().first;
            pq.pop();
            
            if(u==n-1) return d[u];
            if (d1 > d[u])
            continue;
            if(v[u])continue;
            v[u]=1;
            for(auto [v,w]:g[u]){
                if(d[u]+w<d[v]){
                    d[v]=d[u]+w;
                    pq.push({d[v],v});
                }
            }
            
        }
        return -1;
    }
};