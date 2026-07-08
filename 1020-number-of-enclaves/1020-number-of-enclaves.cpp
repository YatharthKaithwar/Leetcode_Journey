class Solution {
private:
    void DFS(vector<vector<int>>& grid,int i, int j){
        int m = grid.size();
        int n = grid[0].size();


        if(i<0 || i>=m || j<0 || j>=n ||grid[i][j]==0){ // if it is beyond the grid
            return;
        }
        grid[i][j]=0;
        // for check  all 4 directions
        DFS(grid, i + 1, j);
        DFS(grid, i - 1, j);
        DFS(grid, i, j + 1);
        DFS(grid, i, j - 1);
    }
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        for(int i=0; i<m; i++){
            for(int j=0; j<n ; j++){
                if(i==0 || i==m-1 || j==0 || j==n-1 ){ // if we are at the boundry and a land cell
                    if(grid[i][j]==1){   //checking for land cell
                        DFS(grid,i,j);
                    }
                }
            }
        }
        int enclaveCount = 0;
        for(int i=0; i<m; i++){ // for counting rest of the land cell if present in the grid
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    enclaveCount++;
                }
            }
        }
        return enclaveCount;
    }
};