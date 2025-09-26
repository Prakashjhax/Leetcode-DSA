class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;

        int i = 0;  // pointer to the last unique element
        for (int j = 1; j < nums.size(); j++) {
            if (nums[j] != nums[i]) {   // found a new unique element
                i++;
                nums[i] = nums[j];      // place it in the next position
            }
        }
        return i + 1; // number of unique elements
    }
};