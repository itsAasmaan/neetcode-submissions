class Solution {
   public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool rows[9][10] = {false};
        bool cols[9][10] = {false};
        bool boxes[9][10] = {false};

        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] == '.') {
                    continue;
                }

                int val = board[i][j] - '0';
                int box_index = (i / 3) * 3 + (j / 3);
                if (rows[i][val] || cols[j][val] || boxes[box_index][val]) {
                    return false;
                }

                rows[i][val] = true;
                cols[j][val] = true;
                boxes[box_index][val] = true;
            }
        }

        return true;
    }
};
