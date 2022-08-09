class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        map<int, long> dp;
        for (int i = 0; i < arr.size(); i++) {
            dp.insert(pair<int, long>(arr[i], 1));
            for (map<int, long>::iterator iter = dp.begin(); iter != dp.end(); iter++) {
                if (arr[i] % iter->first == 0 && dp.find(arr[i] / iter->first) != dp.end()) {
                    dp.find(arr[i])->second += (iter->second * dp.find(arr[i] / iter->first)->second);
                }
            }
        }
        long ans = 0;
        for (map<int, long>::iterator iter = dp.begin(); iter != dp.end(); iter++) {
            ans += iter->second;
        }
        return ans % 1000000007;
    }
};