// class Solution {
// private:
// void BFS(int row, int col, vector<vector<int>> &visited,vector<vector<char>>& grid ){
//    visited[row][col]=1;
//    queue<pair<int,int>> q;
//   q.push({row,col});
//    int n =grid.size();
//    int m =grid[0].size(); 
//
//    while(!q.empty()){
//        int row = q.front().first;
//        int col = q.front().second;
//       q.pop();
//
//        for (int deltaRow = -1; deltaRow <=1; deltaRow ++ ){
//            for (int deltaCol = -1; deltaCol<=1; deltaCol++){
//             int neighbourRow = row + deltaRow;
//             int neighbourCol = col + deltaCol;

             // if(neighbourRow>=0 && neighbourRow < n && neighbourCol>=0 && neighbourCol< m && grid[neighbourRo[neighbourCol]=='1' && !visited[neighbourRow][neighbourCol]){
//                visited[neighbourRow][neighbourCol] = 1;
//                q.push({neighbourRow,neighbourCol});
//             }
//            }
//        }
//    }
//}
//public:
//   int numIslands(vector<vector<char>>& grid) {
//        int n = grid.size();
//        int m = grid[0].size();
//        vector <vector <int>> visited(n, vector<int>(m,0));
//        int islands =0;
//        for(int row = 0;row<n; row++){
//            for(int col = 0 ; col<m ; col++){
//                if(!visited[row][col] && grid[row][col] == '1'){
//                    islands++;
//                    BFS(row, col, visited, grid);
//                }
//           }
//        }
//       return islands;
//    }
//};







class Solution {
private:
    void BFS(int row, int col, vector<vector<int>> &visited, vector<vector<char>>& grid) {
        visited[row][col] = 1;

        queue<pair<int, int>> q;
        q.push({row, col});

        int n = grid.size();
        int m = grid[0].size();

        int deltaRow[] = {-1, 0, 1, 0};
        int deltaCol[] = {0, 1, 0, -1};

        while (!q.empty()) {
            int currentRow = q.front().first;
            int currentCol = q.front().second;
            q.pop();

            for (int i = 0; i < 4; i++) {
                int neighbourRow = currentRow + deltaRow[i];
                int neighbourCol = currentCol + deltaCol[i];

                if (neighbourRow >= 0 && neighbourRow < n &&
                    neighbourCol >= 0 && neighbourCol < m &&
                    grid[neighbourRow][neighbourCol] == '1' &&
                    !visited[neighbourRow][neighbourCol]) {

                    visited[neighbourRow][neighbourCol] = 1;
                    q.push({neighbourRow, neighbourCol});
                }
            }
        }
    }

public:
    int numIslands(vector<vector<char>>& grid) {

        if (grid.empty()) return 0;

        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> visited(n, vector<int>(m, 0));  // To store visted pair of nodes 

        int islands = 0;

        for (int row = 0; row < n; row++) {
            for (int col = 0; col < m; col++) {
                if (!visited[row][col] && grid[row][col] == '1') { //checking if already visted
                    islands++;
                    BFS(row, col, visited, grid);
                }
            }
        }

        return islands;
    }
};