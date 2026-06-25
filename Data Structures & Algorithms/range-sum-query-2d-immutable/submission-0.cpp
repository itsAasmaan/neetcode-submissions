class NumMatrix {
public:
    vector<vector<int>>mat;
    NumMatrix(vector<vector<int>>& matrix) {
        mat = matrix;
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int rowLen = row2 - row1 + 1;
        int colLen = col2 - col1 + 1;

        vector<vector<bool>>visited(rowLen, vector<bool>(colLen, false));

        int result = 0;
        for (int i=0; i<rowLen; i++) {
            for (int j=0; j<colLen; j++) {
                if (!visited[i][j]) {
                    visited[i][j] = true;
                    result += mat[row1+i][col1+j];
                }
            }
        }

        return result;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */