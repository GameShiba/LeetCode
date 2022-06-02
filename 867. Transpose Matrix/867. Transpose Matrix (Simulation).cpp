class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int column = matrix[0].size();
        vector<vector<int>> transpose(column);
        for (int X = 0; X < row; X++) {
            for (int Y = 0; Y < column; Y++)
                transpose[Y].push_back(matrix[X][Y]);
        }
        return transpose;
    }
};