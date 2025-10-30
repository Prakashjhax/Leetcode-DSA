class Solution {
public:
    void solve(int i, vector<int>& candidates, int target, vector<int>& current, vector<vector<int>>& ans) {
        // base case: target achieved
        if (target == 0) {
            ans.push_back(current);
            return;
        }

        // base case: out of range or target < 0
        if (i == candidates.size() || target < 0)
            return;

        // include current element
        current.push_back(candidates[i]);
        solve(i, candidates, target - candidates[i], current, ans);
         // same index since we can reuse element
        current.pop_back(); // backtrack

        // skip current element
        solve(i + 1, candidates, target, current, ans);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> current;
        solve(0, candidates, target, current, ans);
        return ans;
    }
};