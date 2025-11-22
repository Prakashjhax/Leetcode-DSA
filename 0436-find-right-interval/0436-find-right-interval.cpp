class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<pair<int, int>> starts; // {startValue, originalIndex}

        // Store all start points with their original index
        for (int i = 0; i < n; i++) {
            starts.push_back({intervals[i][0], i});
        }

        // Sort by start value
        sort(starts.begin(), starts.end());

        vector<int> result(n, -1);

        // For each interval, find the smallest start >= end using binary search
        for (int i = 0; i < n; i++) {
            int endVal = intervals[i][1];

            // lower_bound finds the first element where start >= endVal
            auto it = lower_bound(starts.begin(), starts.end(),
                                  make_pair(endVal, -1));

            if (it != starts.end()) {
                result[i] = it->second; // original index
            }
        }

        return result;
    }
};
