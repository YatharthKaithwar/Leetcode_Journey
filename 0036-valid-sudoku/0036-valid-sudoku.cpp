class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool rows[9][9] = {false};
        bool cols[9][9] = {false};
        bool boxes[9][9] = {false};

        for (int r = 0; r < 9; ++r) {
            for (int c = 0; c < 9; ++c) {
                // Skip empty cells
                if (board[r][c] == '.') {
                    continue;
                }

                int num = board[r][c] - '1';// Convert char digit ('1'-'9') to 0-indexed integer (0-8)

                int box_idx = (r / 3) * 3 + (c / 3);// Calculate the 3x3 box index (0 to 8)

                // If number is already seen in row, column, or box, it's invalid
                if (rows[r][num] || cols[c][num] || boxes[box_idx][num]) {
                    return false;
                }

                // Mark the number as seen
                rows[r][num] = true;
                cols[c][num] = true;
                boxes[box_idx][num] = true;
            }
        }

        return true;
    }
};