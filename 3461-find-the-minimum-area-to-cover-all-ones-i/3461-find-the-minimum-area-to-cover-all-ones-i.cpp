class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        int mxi=0,mni=n,mnj=m,mxj=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    mni=min(mni,i);
                    mnj=min(mnj,j);
                    mxi=max(mxi,i);
                    mxj=max(mxj,j);
                }
            }
        }
        return (mxi-mni+1)*(mxj-mnj+1);
    }
};