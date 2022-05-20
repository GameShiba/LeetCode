class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int row = obstacleGrid.size();
        int column = obstacleGrid[0].size();
        if (obstacleGrid[0][0] == 1 || obstacleGrid[row - 1][column - 1] == 1)
            return 0;
        vector<vector<int>> DP(row, vector<int>(column));
        DP[0][0] = 1;
        for (int X = 0; X < row; X++) {
            for (int Y = 0; Y < column; Y++) {
                if (X - 1 >=0 && X - 1 < row && obstacleGrid[X][Y] == 0)
                    DP[X][Y] += DP[X - 1][Y];
                if (Y - 1 >=0 && Y - 1 < column && obstacleGrid[X][Y] == 0)
                    DP[X][Y] += DP[X][Y - 1];
            }
        }
        return DP[row - 1][column - 1];
    }
};