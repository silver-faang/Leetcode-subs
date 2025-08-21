class Solution {
public:
    int countSquares(vector<vector<int>>& m) {
        int r=m.size(),c=m[0].size();
        vector<vector<int>> dp(r+1,vector<int>(c+1,0));
        int ans=0;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(m[i][j]==1){
                    dp[i+1][j+1]=min({dp[i][j+1],dp[i+1][j],dp[i][j]})+1;
                    ans+=dp[i+1][j+1];
                }
            }
        }
        return ans;
    }
};