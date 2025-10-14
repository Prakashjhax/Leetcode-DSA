class Solution {
public:
    bool canPlace(vector<int>& position, int m, int dist) {
        int count = 1; // Place first ball
        int lastPos = position[0];
        
        for (int i = 1; i < position.size(); i++) {
            if (position[i] - lastPos >= dist) {
                count++;
                lastPos = position[i];
            }
            if (count >= m) return true; // successfully placed all balls
        }
        return false;
    }

    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end()); // sort basket positions
        
        int left = 1; // minimum possible distance
        int right = position.back() - position.front(); // maximum possible distance
        int ans = 0;
        
        while (left <= right) {
            int mid = left + (right - left) / 2; // try middle distance
            if (canPlace(position, m, mid)) {
                ans = mid;        // mid is possible, try larger distance
                left = mid + 1;
            } else {
                right = mid - 1;  // mid too large, try smaller
            }
        }
        return ans;
    }
};
