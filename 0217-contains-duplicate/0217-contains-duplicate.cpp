class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> s;
        for(int x : nums){
            if(s.count(x)) return true; // duplicate mil gaya
            s.insert(x);
        }
        return false; // agar poore loop me duplicate nahi mila
    }
};
