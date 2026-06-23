class Solution {
public:
    int zigZagArrays(int n, int l, int r) {
        if (n == 1) {
            return r - l + 1;
        }
        
        int m = r - l + 1;
        int MOD = 1e9 + 7;
        
        vector<int> dp0(m + 1, 1);
        vector<int> dp1(m + 1, 1);
        
        for (int i = 2; i <= n; ++i) {
            vector<int> next_dp0(m + 1, 0);
            vector<int> next_dp1(m + 1, 0);
            
            int sum1 = 0;
            for (int x = 1; x <= m; ++x) {
                next_dp0[x] = sum1;
                sum1 = (sum1 + dp1[x]) % MOD;
            }
            
            int sum0 = 0;
            for (int x = m; x >= 1; --x) {
                next_dp1[x] = sum0;
                sum0 = (sum0 + dp0[x]) % MOD;
            }
            
            dp0 = move(next_dp0);
            dp1 = move(next_dp1);
        }
        
        int ans = 0;
        for (int x = 1; x <= m; ++x) {
            ans = (ans + dp0[x]) % MOD;
            ans = (ans + dp1[x]) % MOD;
        }
        
        return ans;
    }
};
