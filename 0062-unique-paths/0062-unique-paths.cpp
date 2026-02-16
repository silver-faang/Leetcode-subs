class Solution {
public:
    int uniquePaths(int m, int n) {
        long ans=1;
        int r=m-1;
        int c=n-1;
        for(int i=1;i<=r;i++){
            ans=ans*(c+i)/i;
                
        }
        return ans;
    }
};