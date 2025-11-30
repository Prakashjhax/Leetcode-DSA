class Solution {
public:
    bool canJump(vector<int>& nums) {
        int reachable = 0; // farthest index we can reach
        
        for (int i = 0; i < nums.size(); i++) {
            if (i > reachable) return false;    // we cannot move further
            reachable = max(reachable, i + nums[i]);
        }
        
        return true;
    }
};
