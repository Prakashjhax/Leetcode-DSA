#include <bits/stdc++.h>
using namespace std;

class SnapshotArray {
public:
    int snap_id;
    vector<map<int, int>> arr;

    SnapshotArray(int length) {
        snap_id = 0;
        arr.resize(length);
        // Initially, all values are 0 at snap_id = 0
        for (int i = 0; i < length; i++)
            arr[i][0] = 0;
    }
    
    void set(int index, int val) {
        // Set value for the current snap_id
        arr[index][snap_id] = val;
    }
    
    int snap() {
        // Return current snap_id and increment for next time
        return snap_id++;
    }
    
    int get(int index, int snap_id_query) {
        // Find the latest snap_id ≤ snap_id_query
        auto it = arr[index].upper_bound(snap_id_query);
        it--;  // move one step back
        return it->second;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */
