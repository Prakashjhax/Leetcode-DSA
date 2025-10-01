class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";

        string prefix = strs[0]; // pehli string ko prefix maan lo

        for (int i = 1; i < strs.size(); i++) {
            // Jab tak prefix current string ka starting part nahi hai
            while (strs[i].find(prefix) != 0) {
                prefix = prefix.substr(0, prefix.size() - 1); // prefix chhota karte raho
                if (prefix.empty()) return ""; // agar empty ho gaya to koi common prefix nahi hai
            }
        }
        return prefix;
    }
};