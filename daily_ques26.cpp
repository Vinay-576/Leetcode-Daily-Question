class Solution {
    vector<int> tree;
    
    void update(int node, int start, int end, int idx, int val) {
        if (start == end) {
            tree[node] = val;
            return;
        }
        int mid = start + (end - start) / 2;
        if (idx <= mid) {
            update(2 * node, start, mid, idx, val);
        } else {
            update(2 * node + 1, mid + 1, end, idx, val);
        }
        tree[node] = max(tree[2 * node], tree[2 * node + 1]);
    }
    
    int query(int node, int start, int end, int l, int r) {
        if (l > end || r < start) {
            return 0;
        }
        if (l <= start && end <= r) {
            return tree[node];
        }
        int mid = start + (end - start) / 2;
        return max(query(2 * node, start, mid, l, r), 
                   query(2 * node + 1, mid + 1, end, l, r));
    }
    
public:
    vector<bool> getResults(vector<vector<int>>& queries) {
        int max_x = 0;
        for (const auto& q : queries) {
            max_x = max(max_x, q[1]);
        }
        
        // Use a flat array for the segment tree to optimize memory and speed
        tree.assign(4 * max_x + 4, 0);
        set<int> obstacles;
        obstacles.insert(0); // Origin is our starting obstacle
        
        vector<bool> ans;
        
        for (const auto& q : queries) {
            if (q[0] == 1) {
                int x = q[1];
                auto it = obstacles.upper_bound(x);
                int R = (it != obstacles.end()) ? *it : -1;
                
                it--;
                int L = *it;
                
                obstacles.insert(x);
                
                // Update the gap ending at the newly placed obstacle
                update(1, 0, max_x, x, x - L);
                
                // If there is an obstacle to the right, update its gap as well
                if (R != -1) {
                    update(1, 0, max_x, R, R - x);
                }
            } else {
                int x = q[1];
                int sz = q[2];
                
                auto it = obstacles.upper_bound(x);
                it--;
                int L = *it; // The closest obstacle before or at x
                
                // The max available space is either a completely formed gap before L,
                // or the space between L and the query endpoint x.
                int max_gap = query(1, 0, max_x, 0, L);
                max_gap = max(max_gap, x - L);
                
                ans.push_back(max_gap >= sz);
            }
        }
        
        return ans;
    }
};
