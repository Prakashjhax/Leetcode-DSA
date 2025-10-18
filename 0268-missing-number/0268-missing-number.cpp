class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int total = n * (n + 1) / 2; // Sum of numbers from 0 to n
        int sum = 0;
        for (int num : nums) {
            sum += num; // Sum of all elements in the array
        }
        return total - sum; // Missing number
    }
};
