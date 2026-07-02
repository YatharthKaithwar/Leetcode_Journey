class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
         int m = matrix.size();       // Number of rows
        int n = matrix[0].size();    // Number of columns
        
        // Initialize an empty result matrix with swapped dimensions (n rows by m columns)
        std::vector<std::vector<int>> ans(n, std::vector<int>(m));
        
        // Map original row and column indices to the transposed position
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                ans[j][i] = matrix[i][j];
            }
        }
        
        return ans;
    }
};