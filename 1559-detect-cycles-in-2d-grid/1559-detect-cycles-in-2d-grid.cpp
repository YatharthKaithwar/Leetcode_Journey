class Solution {
public:
    bool containsCycle(vector<vector<char>>& grid) {
         int m = grid.size();
        int n = grid[0].size();
        
        std::vector<std::vector<bool>> visited(m, std::vector<bool>(n, false));
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (!visited[i][j]) {
                    if (dfs(grid, visited, i, j, -1, -1, grid[i][j])) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
    
private:
    bool dfs(std::vector<std::vector<char>>& grid, std::vector<std::vector<bool>>& visited, 
             int r, int c, int prevR, int prevC, char target) {
        
        visited[r][c] = true;
        
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};
        
        for (int i = 0; i < 4; ++i) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            
            // Check boundary and ensure the character matches
            if (nr >= 0 && nr < grid.size() && nc >= 0 && nc < grid[0].size() && grid[nr][nc] == target) {
                // If the neighbor is already visited and is not the cell we came from, a cycle is found
                if (nr != prevR || nc != prevC) {
                    if (visited[nr][nc]) {
                        return true;
                    }
                    if (dfs(grid, visited, nr, nc, r, c, target)) {
                        return true;
                    }
                }
            }
        }
        
        return false;
    }
};