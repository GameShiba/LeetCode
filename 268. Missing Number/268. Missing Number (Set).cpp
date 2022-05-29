class Solution {
public:
    int missingNumber(vector<int>& nums) {
        set<int> set;
        for (int i = 0; i < nums.size(); i++) {
            set.insert(nums[i]);
        }
        int missing = -1;
        for (int i = 0; i <= nums.size(); i++) {
            if (!set.count(i)) {
                missing = i;
                break;
            }
        }
        return missing;
    }
};