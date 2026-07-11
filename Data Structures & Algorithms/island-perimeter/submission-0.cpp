class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int result  = 0;
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                if (grid[i][j] == 1) {
                    int directions[] = {-1, 0, 1, 0, -1};
                    for (int dir=0; dir<4; dir++) {
                        int newRow = i+directions[dir];
                        int newCol = j+directions[dir+1];
                        if (newRow < 0 || newCol < 0 
                            || newRow >= n || newCol >= m 
                            || grid[newRow][newCol] == 0) {
                            result += 1;
                        }
                    }
                }
            }
        }

        return result;
    }
};