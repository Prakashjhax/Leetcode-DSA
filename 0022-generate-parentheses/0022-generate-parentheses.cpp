class Solution {
public:
    void backtrack(vector<string>& result, string current, int open, int close, int n) {
        // If the current string is of length 2*n, we got one valid combination
        if (current.size() == 2 * n) {
            result.push_back(current);
            return;
        }

        // Add '(' if we can still place one
        if (open < n)
            backtrack(result, current + '(', open + 1, close, n);

        // Add ')' only if there are more '(' placed before it
        if (close < open)
            backtrack(result, current + ')', open, close + 1, n);
    }

    vector<string> generateParenthesis(int n) {
        vector<string> result;
        backtrack(result, "", 0, 0, n);
        return result;
    }
};
