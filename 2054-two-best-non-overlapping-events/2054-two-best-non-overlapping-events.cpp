class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        vector<vector<int>> t;
        for( auto e:events){
            t.push_back({e[0],1,e[2]});
            t.push_back({e[1]+1,0,e[2]});
        }
        int ans=0, mxv=0;
        sort(t.begin(),t.end());
        for(auto tv:t){
            if(tv[1]){
                ans=max(ans,tv[2]+mxv);
            }
            else
             mxv= max(mxv, tv[2]);
        }
        return ans;
    }
};