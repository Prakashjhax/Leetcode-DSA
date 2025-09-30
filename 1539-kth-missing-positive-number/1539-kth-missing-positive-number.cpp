class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int left = 0, right = arr.size() - 1;
        
        // Binary search start
        // hume first index chahiye jaha missing numbers >= k ho
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            // arr[mid] - (mid+1) = missing numbers till mid
            if (arr[mid] - (mid + 1) < k) {
                left = mid + 1; // kth missing number mid ke baad hai
            } else {
                right = mid - 1; // kth missing number mid ya usse pehle hai
            }
        }
        
        // left = number of elements in arr <= kth missing
        // toh kth missing = k + left
        return k + left;
    }
};