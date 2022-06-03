class NumMatrix {
public:
    NumMatrix(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int column = matrix[0].size();
        prefix.resize(row + 1, vector<int>(column + 1));
        for (int X = 0; X < row; X++) {
            for (int Y = 0; Y < column; Y++)
                prefix[X + 1][Y + 1] = prefix[X + 1][Y] + prefix[X][Y + 1] - prefix[X][Y] + matrix[X][Y];
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return prefix[row2 + 1][col2 + 1] - prefix[row1][col2 + 1] - prefix[row2 + 1][col1] + prefix[row1][col1];
    }

private:
    vector<vector<int>> prefix;
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */