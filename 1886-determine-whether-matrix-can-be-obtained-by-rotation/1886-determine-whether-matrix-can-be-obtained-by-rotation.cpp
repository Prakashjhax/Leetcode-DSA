class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        int n = mat.size();
        
        // Try all 4 rotations
        for(int r = 0; r < 4; r++) {
            
            // If mat already matches target
            if(mat == target) return true;

            // Rotate mat 90 degrees clockwise
            // Step 1: Transpose
            for(int i = 0; i < n; i++){
                for(int j = i + 1; j < n; j++){
                    swap(mat[i][j], mat[j][i]);
                }
            }

            // Step 2: Reverse each row
            for(int i = 0; i < n; i++){
                reverse(mat[i].begin(), mat[i].end());
            }
        }
        return false;
    }
};