class Solution {
public:
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        auto check = [&](int md)->bool {
            vector<vector<int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};
            vector<vector<int>> grid (row,vector<int>(col,0));
            for(int i=0;i<md;i++){
                grid[cells[i][0]-1][cells[i][1]-1]=1;
            }
            queue<pair<int,int>> q;
            vector<vector<int>> vis(row,vector<int>(col,0));
            for(int c=0;c<col;c++){
                if(grid[0][c]==0){
                    q.push({0,c});
                    vis[0][c]=1;
                    //break;
                }
            }
            while(!q.empty()){
                auto [r,c]=q.front();
                q.pop();
                if(r==row-1) return true;
                for(auto d: dir){
                    int nr=r+d[0];
                    int nc=c+d[1];
                    if(nr>=0 && nr<row && nc>=0 && nc<col && !vis[nr][nc] && !grid[nr][nc]){
                        vis[nr][nc]=1;
                        q.push({nr,nc});
                    }
                }

            }
                            return false;
        };
        int l=1,r=cells.size();
        int ans=0;
        while(l<=r){
            int md=(l+r)/2;
            if(check(md)){
                ans=max(ans,md);
                l=md+1;
            }
            else r=md-1;
        }
        return ans;

    }
};