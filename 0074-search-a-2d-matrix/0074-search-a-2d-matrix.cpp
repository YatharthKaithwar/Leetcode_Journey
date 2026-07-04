class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
         if (matrix.empty() || matrix[0].empty()) return false;

        int m = matrix.size();       // Number of rows
        int n = matrix[0].size();    // Number of columns

        int low = 0;
        int high = (m * n) - 1;      // Total elements minus 1

        while (low <= high) {
            int mid = low + (high - low) / 2;

            // Map the 1D index back to 2D coordinates
            int row = mid / n;
            int col = mid % n;

            int midValue = matrix[row][col];

            if (midValue == target) {
                return true; 
            } else if (midValue < target) {
                low = mid + 1;       // Target is in the right half
            } else {
                high = mid - 1;      // Target is in the left half
            }
        }

        return false;
    }
};