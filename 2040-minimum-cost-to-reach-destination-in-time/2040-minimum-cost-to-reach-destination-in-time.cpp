#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int cost[1001];
    int time[1001];
    int dijkstra(int src,int dest, int maxt, vector<int> & fees,vector<vector<pair<int,int>>> &adj){
        for (int i = 0; i <= dest; i++) {
            cost[i] = INT_MAX;
            time[i] = INT_MAX;
        }
        time[0]=0;
        cost[0]=fees[0];
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({cost[0],0,0});
        while(pq.size()){
            int u=pq.top()[2], t=pq.top()[1],c=pq.top()[0];
            pq.pop();
            for(auto itr : adj[u]){
                int v=itr.first, tt=itr.second;
                if(t+tt<=maxt){
                    if(cost[v]>=c+fees[v]){
                        cost[v]=c+fees[v];
                        time[v]=t+tt;
                        pq.push({cost[v],time[v],v});
                    }
                    else if(time[v]>t+tt){
                        time[v]=t+tt;
                        pq.push({c+fees[v],time[v],v});
                    }
                }
            }
        }
        return cost[dest];
    }
    int minCost(int maxTime, vector<vector<int>>& edges, vector<int>& fees) {
        int m=edges.size(),n=fees.size();
        vector<vector<pair<int,int>>>adj(n);
        for(int i=0;i<m;i++){
            adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
            adj[edges[i][1]].push_back({edges[i][0],edges[i][2]});
        }
        
        
        int ans=dijkstra(0,n-1,maxTime,fees,adj);
        if(ans==INT_MAX) return -1;
        return ans;
    }
};