class Solution {
public:
    int longestValidParentheses(string s) {
        int maxLength = 0;
        stack<int> stack;
        stack.push(-1);
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(')
                stack.push(i);
            else {
                stack.pop();
                if (stack.empty())
                    stack.push(i);
                else
                    maxLength = max(maxLength, i - stack.top());
            }
        }
        return maxLength;
    }
};