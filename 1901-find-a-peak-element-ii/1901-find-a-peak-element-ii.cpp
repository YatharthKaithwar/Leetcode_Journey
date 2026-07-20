class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        
        int low = 0;
        int high = n - 1;
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            
            // Step 1: Find the row index of the maximum element in the mid column
            int maxRow = 0;
            for (int i = 0; i < m; ++i) {
                if (mat[i][mid] > mat[maxRow][mid]) {
                    maxRow = i;
                }
            }
            
            // Step 2: Retrieve neighbor values (default to -1 if out of bounds)
            int leftNeighbor = (mid > 0) ? mat[maxRow][mid - 1] : -1;
            int rightNeighbor = (mid < n - 1) ? mat[maxRow][mid + 1] : -1;
            
            // Step 3: Check if the current element is a 2D peak
            if (mat[maxRow][mid] > leftNeighbor && mat[maxRow][mid] > rightNeighbor) {
                return {maxRow, mid};
            }
            
            // Step 4: Move toward the strictly greater neighbor
            if (rightNeighbor > mat[maxRow][mid]) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        
        return {-1, -1}; 
    }
};