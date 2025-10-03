class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result = 0;
        for (int num : nums) {
            result ^= num;   // XOR with each element
        }
        return result;       // the unique number remains
    }
};