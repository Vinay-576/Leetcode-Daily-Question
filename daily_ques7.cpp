class Solution {
public:
    int maximumJumps(vector<int>& nums, int target) {
        int n = nums.size();
        // dp[i] stores the max jumps to reach index i
        vector<int> dp(n, -1);
        dp[0] = 0; // Starting point

        for (int j = 1; j < n; ++j) {
            for (int i = 0; i < j; ++i) {
                // Check if index i is reachable and jump is within target
                if (dp[i] != -1 && abs(nums[j] - nums[i]) <= target) {
                    dp[j] = max(dp[j], dp[i] + 1);
                }
            }
        }

        return dp[n - 1];
    }
};
