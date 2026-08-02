class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
          int m = mat.size();
        int n = mat[0].size();
        
        // If the total number of elements does not match, reshaping is impossible
        if (m * n != r * c) {
            return mat;
        }
        
        // Initialize the new reshaped matrix with r rows and c columns
        std::vector<std::vector<int>> reshaped(r, std::vector<int>(c));
        
        // Map the elements using a single linear tracking counter
        int count = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                // Calculate the position in the new matrix
                reshaped[count / c][count % c] = mat[i][j];
                count++;
            }
        }
        
        return reshaped;
    }
};