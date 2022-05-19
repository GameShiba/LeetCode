class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int column = matrix[0].size();
        if (!row || !column)
            return 0;
        int direction[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        vector<vector<int>> outDegrees = vector<vector<int>>(row, vector<int>(column));
        for (int X = 0; X < row; X++) {
            for (int Y = 0; Y < column; Y++) {
                for (int i = 0; i < 4; i++) {
                    int newX = X + direction[i][0];
                    int newY = Y + direction[i][1];
                    if (newX >= 0 && newX < row && newY >=0 && newY < column && matrix[newX][newY] > matrix[X][Y])
                        outDegrees[X][Y]++;
                }
            }
        }
        queue<pair<int, int>> queue;
        for (int X = 0; X < row; X++) {
            for (int Y = 0; Y < column; Y++) {
                if (outDegrees[X][Y] == 0)
                    queue.push({X,Y});
            }
        }
        int length = 0;
        while (!queue.empty()) {
            length++;
            int queueSize = queue.size();
            for (int i = 0; i < queueSize; i++) {
                int X = queue.front().first;
                int Y = queue.front().second;
                queue.pop();
                for (int j = 0; j < 4; j++) {
                    int newX = X + direction[j][0];
                    int newY = Y + direction[j][1];
                    if (newX >= 0 && newX < row && newY >=0 && newY < column && matrix[newX][newY] < matrix[X][Y]) {
                        outDegrees[newX][newY]--;
                        if (outDegrees[newX][newY] == 0)
                            queue.push({newX, newY});
                    }
                }
            }
        }
        return length;
    }
};