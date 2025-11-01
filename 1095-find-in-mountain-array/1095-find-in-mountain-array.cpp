/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n = mountainArr.length();

        // --- Step 1: Find peak index ---
        int left = 0, right = n - 1;
        while (left < right) {
            int mid = (left + right) / 2;
            if (mountainArr.get(mid) < mountainArr.get(mid + 1))
                left = mid + 1;
            else
                right = mid;
        }
        int peak = left;

        // --- Helper: Binary search on ascending part ---
        auto binarySearchAsc = [&](int l, int r) {
            while (l <= r) {
                int mid = (l + r) / 2;
                int val = mountainArr.get(mid);
                if (val == target) return mid;
                else if (val < target) l = mid + 1;
                else r = mid - 1;
            }
            return -1;
        };

        // --- Helper: Binary search on descending part ---
        auto binarySearchDesc = [&](int l, int r) {
            while (l <= r) {
                int mid = (l + r) / 2;
                int val = mountainArr.get(mid);
                if (val == target) return mid;
                else if (val > target) l = mid + 1;
                else r = mid - 1;
            }
            return -1;
        };

        // --- Step 2: Search left (increasing part) ---
        int index = binarySearchAsc(0, peak);
        if (index != -1) return index;

        // --- Step 3: Search right (decreasing part) ---
        return binarySearchDesc(peak + 1, n - 1);
    }
};
