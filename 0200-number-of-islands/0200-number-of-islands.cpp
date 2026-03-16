class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty()) return 0;
        int n = grid.size(), m = grid[0].size();
        
        // Use std::function to allow the lambda to call itself recursively
        // or declare the lambda and pass a reference to itself.
        vector<vector<int>> vis(n, vector<int>(m, 0));
        
        function<void(int, int)> dfs = [&](int i, int j) {
            vis[i][j] = 1;
            int dx[] = {-1, 0, 1, 0};
            int dy[] = {0, -1, 0, 1};
            
            for (int k = 0; k < 4; k++) {
                int ni = i + dx[k];
                int nj = j + dy[k];
                
                // Boundary check MUST happen before accessing the grid or vis matrix
                if (ni >= 0 && ni < n && nj >= 0 && nj < m && 
                    !vis[ni][nj] && grid[ni][nj] == '1') {
                    dfs(ni, nj);
                }
            }
        };

        int count = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!vis[i][j] && grid[i][j] == '1') {
                    dfs(i, j);
                    count++;
                }
            }
        }
        return count;
    }
};
