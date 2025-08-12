#define ll long long
class Solution {
public:
    int numberOfWays(int n, int x) {
        ll md=1e9+7;
        vector<vector<ll>> dp(n+1,vector<ll>(n+1));
        dp[0][0]=1;
        for(int i=1;i<=n;i++){
            ll v=pow(i,x);
            for(int j=0;j<=n;j++){
                dp[i][j]=dp[i-1][j];
                if(j>=v){
                    dp[i][j]=(dp[i][j]+dp[i-1][j-v])%md;
                }
            }
        }
        return dp[n][n];
    }
};