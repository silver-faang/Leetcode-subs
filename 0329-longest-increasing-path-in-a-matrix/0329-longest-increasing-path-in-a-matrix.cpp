#define f first
#define s second
class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n=matrix.size(), m=matrix[0].size();
        vector<vector<int>> indg(n,vector<int>(m,0));
        vector<pair<int,int>> ngbr {{1,0},{-1,0},{0,1},{0,-1}};
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                for(auto d:ngbr){
                    if(i+d.first<n && i+d.first>=0 && j+d.second<m && j+d.second>=0)
                    if(matrix[i][j]>matrix[i+d.first][j+d.second])
                     indg[i][j]++;
                }
                
            }
        }
		for(int i=0;i<n;i++)
		 for(int j=0;j<m;j++)
		  if(indg[i][j]==0)
                 {q.push({i,j});
				  cout<<i<<" here "<<j<<endl;} 
        int mx=0; // counted using level wise traversal of bfs
        while(q.size()){
			int sz=q.size();
			for(int itr=0;itr<sz;itr++){   // levels
				auto a=q.front();
				int i=a.f, j=a.s;
				q.pop();
				for(auto d:ngbr){
					int ni=i+d.f, nj=j+d.s;
					if(ni>=0 && ni<n && nj>=0 && nj<m && matrix[ni][nj]>matrix[i][j]){
						indg[ni][nj]--;
						if(indg[ni][nj]==0)
						{q.push({ni,nj});
					cout<<ni<<" "<<nj<<endl;}
					}
				}
			}
            mx++;    // increment for levels of bfs
        }
        return mx;}
};