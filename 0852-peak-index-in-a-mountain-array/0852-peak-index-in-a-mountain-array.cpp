class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int start = 0, end = arr.size() - 1;
        
        while (start < end) {
            int mid = start + (end - start) / 2;
            
            if (arr[mid] < arr[mid + 1]) {
                // right side move 
                start = mid + 1;
            } else {
                // left side move 
                end = mid;
            }
        }
        
        return start; // start == end at peak
    }
};
