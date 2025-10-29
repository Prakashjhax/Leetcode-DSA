class Solution {
public:
    int myAtoi(string s) {
        int i = 0, n = s.size();

        // 1. Ignore leading spaces
        while (i < n && s[i] == ' ') i++;

        // 2. Check sign
        int sign = 1;
        if (i < n && (s[i] == '+' || s[i] == '-')) {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }

        // 3. Convert number
        long num = 0;
        while (i < n && isdigit(s[i])) {
            num = num * 10 + (s[i] - '0');

            // 4. Handle overflow
            if (num * sign > INT_MAX) return INT_MAX;
            if (num * sign < INT_MIN) return INT_MIN;

            i++;
        }

        // 5. Return final result
        return (int)(num * sign);
    }
};
