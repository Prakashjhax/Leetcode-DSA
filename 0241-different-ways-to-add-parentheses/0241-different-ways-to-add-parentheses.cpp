class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        return solve(expression);
    }

private:
    unordered_map<string, vector<int>> memo;

    vector<int> solve(string s) {
        if (memo.count(s)) return memo[s];

        vector<int> res;
        for (int i = 0; i < s.size(); i++) {
            char c = s[i];
            if (c == '+' || c == '-' || c == '*') {
                vector<int> left = solve(s.substr(0, i));
                vector<int> right = solve(s.substr(i + 1));

                for (int a : left) {
                    for (int b : right) {
                        if (c == '+') res.push_back(a + b);
                        else if (c == '-') res.push_back(a - b);
                        else res.push_back(a * b);
                    }
                }
            }
        }

        // If no operator was found, it's a number
        if (res.empty()) {
            res.push_back(stoi(s));
        }

        return memo[s] = res;
    }
};