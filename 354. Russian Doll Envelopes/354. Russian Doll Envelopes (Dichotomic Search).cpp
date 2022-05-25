class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), [](const vector<int> &envelopeA, const vector<int> &envelopeB){
            return envelopeA[0] == envelopeB[0] ? envelopeA[1] > envelopeB[1]: envelopeA[0] < envelopeB[0];
        });
        vector<int> DP;
        for(vector<int> envelope: envelopes) {
            vector<int>::iterator iterator = lower_bound(DP.begin(), DP.end(), envelope[1]);
            if (iterator == DP.end())
                DP.push_back(envelope[1]);
            else
                *iterator = envelope[1];
        }
        return DP.size();
    }
};