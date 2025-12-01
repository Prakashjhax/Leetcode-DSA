class Solution {
public:
    int longestPalindrome(string s) {
        
        vector<int> lower(26, 0);
        vector<int> upper(26, 0);

        // Count freq
        for (char c : s) {
            if (c >= 'a' && c <= 'z')
                lower[c - 'a']++;
            else
                upper[c - 'A']++;
        }

        int count = 0;
        bool odd = false;

        for (int i = 0; i < 26; i++) {

            // lower
            if (lower[i] % 2 == 0)
                count += lower[i];
            else {
                count += lower[i] - 1;
                odd = true;
            }

            // upper
            if (upper[i] % 2 == 0)
                count += upper[i];
            else {
                count += upper[i] - 1;
                odd = true;
            }
        }

        return count + odd; // add 1 if any odd exists
    }
};