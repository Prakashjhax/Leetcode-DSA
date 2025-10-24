class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        // Step 1: Pehle array ko sort kar lete hain
        sort(nums.begin(), nums.end());

        int n = nums.size();
        // Step 2: Pehle 3 numbers ka sum leke start karte hain as initial closest
        int closestSum = nums[0] + nums[1] + nums[2];

        // Step 3: Har number ko fix karke baaki 2 ke liye two-pointer lagayenge
        for (int i = 0; i < n - 2; i++) {
            int left = i + 1;      // left pointer agle element par
            int right = n - 1;     // right pointer last element par

            // Jab tak dono pointers cross nahi karte
            while (left < right) {
                int currSum = nums[i] + nums[left] + nums[right];

                // Agar current sum target ke aur close hai, toh update kar do
                if (abs(currSum - target) < abs(closestSum - target)) {
                    closestSum = currSum;
                }

                // Ab decide karte hain pointer move kaise kare
                if (currSum < target) {
                    left++;   // sum chhota hai, toh left badhao (bigger number lo)
                } 
                else if (currSum > target) {
                    right--;  // sum bada hai, toh right ghatayo (smaller number lo)
                } 
                else {
                    // Agar exact match mil gaya toh wahi return kar do
                    return currSum;
                }
            }
        }

        // Step 4: Sab check karne ke baad final closest sum return karo
        return closestSum;
    }
};
