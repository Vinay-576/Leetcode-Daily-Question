class Solution {
    struct Element {
        int val;
        int l;
        int r;
        bool operator<(const Element& other) const {
            return val < other.val;
        }
    };

public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int n = nums.size();
        int max_log = 0;
        while ((1 << max_log) <= n) {
            max_log++;
        }
        
        vector<vector<int>> st_max(n, vector<int>(max_log));
        vector<vector<int>> st_min(n, vector<int>(max_log));
        
        for (int i = 0; i < n; ++i) {
            st_max[i][0] = nums[i];
            st_min[i][0] = nums[i];
        }
        
        for (int j = 1; j < max_log; ++j) {
            for (int i = 0; i + (1 << j) <= n; ++i) {
                st_max[i][j] = max(st_max[i][j - 1], st_max[i + (1 << (j - 1))][j - 1]);
                st_min[i][j] = min(st_min[i][j - 1], st_min[i + (1 << (j - 1))][j - 1]);
            }
        }
        
        vector<int> log_table(n + 1);
        log_table[1] = 0;
        for (int i = 2; i <= n; i++) {
            log_table[i] = log_table[i / 2] + 1;
        }
        
        auto query = [&](int l, int r) {
            int j = log_table[r - l + 1];
            int mx = max(st_max[l][j], st_max[r - (1 << j) + 1][j]);
            int mn = min(st_min[l][j], st_min[r - (1 << j) + 1][j]);
            return mx - mn;
        };
        
        priority_queue<Element> pq;
        for (int i = 0; i < n; ++i) {
            pq.push({query(i, n - 1), i, n - 1});
        }
        
        long long ans = 0;
        for (int i = 0; i < k; ++i) {
            Element top = pq.top();
            pq.pop();
            ans += top.val;
            
            if (top.r > top.l) {
                pq.push({query(top.l, top.r - 1), top.l, top.r - 1});
            }
        }
        
        return ans;
    }
};
