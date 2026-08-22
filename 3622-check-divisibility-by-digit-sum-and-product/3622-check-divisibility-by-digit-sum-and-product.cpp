class Solution {
public:
    bool checkDivisibility(int n) {
        int ds=0,dp=1,m=1;
        int nn=n;
        while(nn){
            int t=nn%10;
            ds+=t;
            dp*=t;
            nn/=10;
        }
        return (n%(ds+dp)==0);
    }
};