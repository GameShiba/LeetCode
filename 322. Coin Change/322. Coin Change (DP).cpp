class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> DP(amount + 1, amount + 1);
        DP[0] = 0;
        for (int i = 1; i <= amount; i++) {
            for (int j = 0; j < coins.size(); j++) {
                if (i >= coins[j])
                    DP[i] = min(DP[i], DP[i - coins[j]] + 1);
            }
        }
        return DP[amount] < amount + 1 ? DP[amount] : -1;
    }
};