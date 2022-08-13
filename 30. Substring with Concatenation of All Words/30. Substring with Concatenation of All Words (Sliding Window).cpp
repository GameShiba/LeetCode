class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        map<string, int> correctHash;
        for (string word : words) {
            correctHash[word]++;
        }
        vector<int> ans;
        for (int i = 0; i < s.size() - words.size() * words[0].size() + 1; i++) {
            map<string, int> currentHash;
            for (int j = 0; j < words.size(); j++) {
                string word = s.substr(i + j * words[0].size(), words[0].size());
                if (!correctHash.count(word)) {
                    break;
                }
                currentHash[word]++;
                if (currentHash[word] > correctHash[word]) {
                    break;
                }
                if (j + 1 == words.size()) {
                    ans.push_back(i);
                }
            }
        }
        return ans;
    }
};