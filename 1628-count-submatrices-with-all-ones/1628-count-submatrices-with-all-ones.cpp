class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int n=mat.size(),m=mat[0].size();
        int res=0;
        vector<vector<int>> r(n,vector<int> (m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(j==0) r[i][j]=mat[i][j];
                else r[i][j]=(mat[i][j]==0)?0:r[i][j-1]+1;
            
            int cur=r[i][j];
            for(int k=i;k>=0;--k){
                cur=min(cur,r[k][j]);
                if(cur==0)break;
                res+=cur;
            }
            }
        }
        return res;
    }
};