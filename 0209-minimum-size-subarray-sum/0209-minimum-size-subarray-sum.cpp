class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int left = 0, sum = 0;
        int minLength = n + 1; // Start with a large impossible value

        for (int right = 0; right < n; ++right) {
            sum += nums[right];  // Expand the window by adding nums[right]

            // Shrink the window from the left while sum >= target
            while (sum >= target) {
                minLength = min(minLength, right - left + 1);
                sum -= nums[left++];
            }
        }

        return (minLength == n + 1) ? 0 : minLength;
    }
};