class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }
        vector<int> sequence;
        sequence.push_back(nums[0]);
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > sequence.back()) {
                sequence.push_back(nums[i]);
            } else {
                int l = 0;
                int r = sequence.size();
                int predecessor = -1;
                while (l <= r) {
                    int mid = (l + r) / 2;
                    if (sequence[mid] < nums[i]) {
                        predecessor = mid;
                        l = mid + 1;
                    } else {
                        r = mid - 1;
                    }
                }
                sequence[predecessor + 1] = nums[i];
            }
        }
        return sequence.size();
    }
};