class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n=s.size(),mxl=0;
        vector<int> dp(n+1,0);
        unordered_set<string> st;
        for(auto str:wordDict){
            st.insert(str);
            mxl=max(mxl,(int)str.size());
        }
        dp[0]=1;
        for(int i=0;i<n;i++){
            for(int j=i;j>=0&&i-j+1<=mxl;j--){
                cout<<i<<" idx "<<j<<endl;
                if(dp[j] && st.count(s.substr(j,i-j+1))){
                 dp[i+1]=true;
                 break;}
            }
        }
        return dp[n];
    }
};