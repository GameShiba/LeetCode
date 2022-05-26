class Solution {
public:
    int hammingWeight(uint32_t n) {
        int hammingWeight = n & 1;
        while (n >>= 1)
            hammingWeight += n & 1;
        return hammingWeight;
    }
};