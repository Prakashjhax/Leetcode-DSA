class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();

        // Step 1: Replace negative numbers, zeros, and numbers > n with a placeholder
        for (int &x : nums) {
            if (x <= 0 || x > n) x = n + 1;
        }

        // Step 2: Mark indices corresponding to values
        for (int i = 0; i < n; i++) {
            int val = abs(nums[i]);
            if (val >= 1 && val <= n) {
                if (nums[val - 1] > 0) {
                    nums[val - 1] = -nums[val - 1];
                }
            }
        }

        // Step 3: First positive index + 1 is the missing number
        for (int i = 0; i < n; i++) {
            if (nums[i] > 0) return i + 1;
        }

        // Step 4: If all indices are marked, missing number is n + 1
        return n + 1;
    }
};
