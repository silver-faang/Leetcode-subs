#define ll long long
class Solution {
public:
   vector<ll> dijkstra(int startchar, vector<vector<pair<int,int>>>& adj){
    priority_queue<pair<ll,int>,vector<pair<ll,int>>, greater<pair<ll,int>>> pq;
    pq.push({0,startchar});
    vector<ll> mncosts(26,-1);
    while(pq.size()){
        auto c=pq.top();
        pq.pop();
        if(mncosts[c.second]!=-1 && mncosts[c.second]<c.first)continue;
        for(auto nxt:adj[c.second]){
            ll newtotal=c.first+nxt.second;
            if(mncosts[nxt.first]==-1 || newtotal<mncosts[nxt.first]){
                mncosts[nxt.first]=newtotal;
                pq.push({newtotal,nxt.first});
            }
        }
    }
    return mncosts;
   }
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        ll tc=0;
        vector<vector<ll>> mncosts(26,vector<ll>(26,INT_MAX));
        for(int i=0;i<original.size();i++){
            mncosts[original[i]-'a'][changed[i]-'a']=min(mncosts[original[i]-'a'][changed[i]-'a'],(ll)cost[i]);
        }
        for (int k = 0; k < 26; ++k) {
            for (int i = 0; i < 26; ++i) {
                for (int j = 0; j < 26; ++j) {
                    mncosts[i][j] =
                        min(mncosts[i][j], mncosts[i][k] + mncosts[k][j]);
                }
            }
        }
        for (int i = 0; i < source.size(); ++i) {
            if (source[i] == target[i]) {
                continue;
            }
            int sourceChar = source[i] - 'a';
            int targetChar = target[i] - 'a';

            if (mncosts[sourceChar][targetChar] >= INT_MAX) {
                return -1;
            }
            tc += mncosts[sourceChar][targetChar];
        }

        return tc;

    }
};