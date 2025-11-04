class Solution {
public:
    vector<int> fairCandySwap(vector<int>& aliceSizes, vector<int>& bobSizes) {
        int sumA = accumulate(aliceSizes.begin(), aliceSizes.end(), 0);
        int sumB = accumulate(bobSizes.begin(), bobSizes.end(), 0);
        int delta = (sumB - sumA) / 2; // difference to balance both sides

        unordered_set<int> bobSet(bobSizes.begin(), bobSizes.end());

        for (int x : aliceSizes) {
            int y = x + delta;
            if (bobSet.count(y)) {
                return {x, y};
            }
        }
        return {}; // guaranteed at least one valid answer exists
    }
};
