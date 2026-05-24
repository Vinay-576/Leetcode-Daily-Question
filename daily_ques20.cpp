class Solution {
    int dp[1001] = {0};

    int dfs(vector<int>& arr, int n, int d, int i) {
        if (dp[i]) return dp[i];
        
        int res = 1;
        
        for (int j = i + 1; j <= min(i + d, n - 1) && arr[j] < arr[i]; ++j) {
            res = max(res, 1 + dfs(arr, n, d, j));
        }
        
        for (int j = i - 1; j >= max(i - d, 0) && arr[j] < arr[i]; --j) {
            res = max(res, 1 + dfs(arr, n, d, j));
        }
        
        return dp[i] = res;
    }

public:
    int maxJumps(vector<int>& arr, int d) {
        int n = arr.size();
        int ans = 1;
        
        for (int i = 0; i < n; ++i) {
            ans = max(ans, dfs(arr, n, d, i));
        }
        
        return ans;
    }
};
