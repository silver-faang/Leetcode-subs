class Solution {
public:
    int numDecoding(string s, int p, vector<int> & dp){
        int n=s.size();
        if(dp[p]>-1) return dp[p];
        if(s[p]=='0') return dp[p]=0;
        int res=numDecoding(s,p+1,dp);
        if(p<n-1 && (s[p]=='1' || (s[p]=='2' && s[p+1]<'7'))) res+=numDecoding(s,p+2,dp);
        return dp[p]=res;
    }
    int numDecodings(string s) {
        vector<int> dp(s.size()+1,-1);
        dp[s.size()]=1;
        return s.empty() ? 0: numDecoding(s,0,dp);
    }
};