class Solution {
public:
    void generate(int index, vector<int>& nums, vector<int>& current,
                  vector<vector<int>>& result) {
        // Add current subset
        result.push_back(current);

        // Explore further elements
        for (int i = index; i < nums.size(); i++) {
            current.push_back(nums[i]);             // include nums[i]
            generate(i + 1, nums, current, result); // move to next
            current.pop_back();                     // backtrack
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> current;
        generate(0, nums, current, result);
        return result;
    }
};
