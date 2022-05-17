class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if (grid[0][0] == 1)
            return -1;
        int n = grid.size();
        int direction[8][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}, {1, 1}, {1, -1}, {-1, -1}, {-1, 1}};
        queue<pair<int, int>> queue;
        queue.emplace(0,0);
        grid[0][0] = 1;
        while (!queue.empty()) {
            int X = queue.front().first;
            int Y = queue.front().second;
            queue.pop();
            if (X == n-1 && Y == n-1)
                return grid[n-1][n-1];
            for (int i = 0; i < 8; i++) {
                int newX = X + direction[i][0];
                int newY = Y + direction[i][1];
                if (newX >= 0 && newY >= 0 && newX < n && newY < n && grid[newX][newY] == 0) {
                    queue.emplace(newX, newY);
                    grid[newX][newY] = grid[X][Y] + 1;
                }
            }
        }
        return -1;
    }
};