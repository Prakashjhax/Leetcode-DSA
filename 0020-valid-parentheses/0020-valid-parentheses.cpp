class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        unordered_map<char, char> match = {
            {')', '('},
            {']', '['},
            {'}', '{'}
        };

        for (char c : s) {
            // if it's an opening bracket, push it
            if (c == '(' || c == '[' || c == '{') {
                st.push(c);
            } 
            // if it's a closing bracket
            else {
                if (st.empty() || st.top() != match[c]) {
                    return false;
                }
                st.pop();
            }
        }
        // stack must be empty for valid parentheses
        return st.empty();
    }
};
