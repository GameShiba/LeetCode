class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> DP(m + 1, vector<int>(n + 1));
        for (int i = 0; i < strs.size(); i++) {
            int zeros = 0;
            int ones = 0;
            for (int j = 0; j < strs[i].length(); j++) {
                if (strs[i][j] == '0')
                    zeros++;
                else
                    ones++;
            }
            for (int j = m; j - zeros >= 0; j--) {
                for (int k = n; k - ones >= 0; k--) {
                    DP[j][k] = max(DP[j][k], DP[j - zeros][k - ones] + 1);
                }
            }
        }
        return DP[m][n];
    }
};