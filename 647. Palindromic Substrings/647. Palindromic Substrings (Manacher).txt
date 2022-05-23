class Solution {
public:
    int countSubstrings(string s) {
        string manacherStr = "$#";
        for (char c : s) {
            manacherStr += c;
            manacherStr += '#';
        }
        manacherStr += '!';
        vector<int> manacher(manacherStr.size());
        int iMax = 0;
        int rMax = 0;
        int maxNum = 0;
        for (int i = 1; i < manacherStr.size(); i++) {
            manacher[i] = (i <= rMax) ? min (manacher[iMax - (i - iMax)], rMax - i + 1) : 1;
            while (manacherStr[i + manacher[i]] == manacherStr[i - manacher[i]])
                manacher[i]++;
            if (i + manacher[i] - 1 > iMax) {
                iMax = i;
                rMax = i + manacher[i] - 1;
            }
            maxNum += manacher[i] / 2;
        }
        return maxNum;
    }
};