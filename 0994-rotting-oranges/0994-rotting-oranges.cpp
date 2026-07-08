class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue <pair<pair<int,int>, int>> q;    //     for storing   {{row,col},time} as queue
        int visited[n][m];
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){           // if grid has rotten(2) orange
                    q.push({{i,j},0});       // pushing in queue with 0 minute
                    visited[i][j] = 2;       // marking the same orange in vistied one as rotten(2)
                }
                else{
                    visited[i][j]=0;         // else there is no orange
                }
            }
        }

        int tm = 0;
        int deltaRow[] = {-1,0,+1,0};
        int deltaCol[] = {0,+1,0,-1};

        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int time = q.front().second;
            tm = max(tm,time);
            q.pop();

            for (int i = 0; i<4;i++){
            int nrow = row + deltaRow[i];
            int ncol = col + deltaCol[i];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && visited[nrow][ncol]==0 && grid[nrow][ncol]==1){
                q.push({{nrow,ncol}, time+1}); // if orange is not visted and fresh in the grid
                visited[nrow][ncol] = 2;       // marking it as a rotten orange in visited array
            }
            }
        }
        for(int i = 0 ; i<n ; i++){      //  for checking if there is still a fresh orange left or not 
            for(int j=0 ; j<m ; j++){        //  as there may be some oranges without any neighbour
                if(visited[i][j]!=2 && grid[i][j]==1) return -1;
            }
        }
        return tm;
    }
};