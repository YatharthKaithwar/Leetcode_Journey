class Solution {
private:
    void DFS(int row, int col, vector<vector<int>>& ans, vector<vector<int>>& image, int color,
    int deltaRow[], int deltaCol[], int initialColor){
        ans[row][col] = color;
        int n = image.size();
        int m = image[0].size();

        for(int i = 0; i<4; i++){
            int neighbourRow = row + deltaRow[i];
            int neighbourCol = col + deltaCol[i];
            if(neighbourRow>=0 && neighbourRow<n && neighbourCol>=0 && neighbourCol < m && image[neighbourRow][neighbourCol] == initialColor && ans[neighbourRow][neighbourCol] != color){
                DFS(neighbourRow, neighbourCol, ans , image, color, deltaRow, deltaCol, initialColor);
            }
        }

    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int initialColor = image[sr][sc];
        vector<vector<int>> ans = image;
        int deltaRow[]={-1,0,+1,0};
        int deltaCol[]={0,+1,0,-1};
        DFS(sr, sc, ans, image, color, deltaRow, deltaCol ,initialColor);
        return ans;
    }
};