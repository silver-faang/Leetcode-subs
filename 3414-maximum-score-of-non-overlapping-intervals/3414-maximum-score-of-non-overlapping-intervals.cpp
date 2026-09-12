class Solution {
public:
    vector<int> nxtIdx;
    struct Node{
        long long score=-1;
        vector<int> idxs;
    };
    int findNext(vector<vector<int>> &intervals, int idx){
        int l=0,r=intervals.size()-1;
        int res=r+1;
        while(l<=r){
            int md=l+(r-l)/2;
            if(intervals[md][0]>idx){
                res=md;
                r=md-1;
            }
            else l=md+1;
        }
        return res;
    }
    vector<vector<Node>> dp;
    Node solve( vector<vector<int>> & intervals, int i, int k){
        if(i>=intervals.size()|| k==0) return Node();
        if(dp[i][k].score!=-1)return dp[i][k];
        Node skip= solve(intervals,i+1,k);
        int wt=intervals[i][2];
        int idx=intervals[i][3];
        int j=nxtIdx[i];
        Node temp=solve(intervals,j,k-1);
        Node take;
        take.score=temp.score+wt;
        temp.idxs.push_back(idx);
        take.idxs=temp.idxs;
        sort(begin(take.idxs),end(take.idxs));
        Node res;
        if(skip.score>take.score)
         res=skip;
        else if(skip.score<take.score)
         res=take;
        else res=(skip.idxs<take.idxs)?skip:take;
        return dp[i][k]=res;
          
    }
    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n= intervals.size();
        for(int i=0;i<n;i++){
            intervals[i].push_back(i);
        }
        sort(intervals.begin(),intervals.end());
        nxtIdx.resize(n);
        for(int i=0;i<n;i++){
            int r=intervals[i][1];
            nxtIdx[i]=findNext(intervals,r);
        }
        int k=4;
        dp.assign(n+1,vector<Node>(k+1));
        return solve(intervals,0,k).idxs;
    }
};