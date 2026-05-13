class Solution {
public:
    int minMoves(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<int> diff(2 * limit + 2, 0);

        for (int i = 0; i < n / 2; ++i) {
            int a = nums[i];
            int b = nums[n - 1 - i];

            int l = min(a, b) + 1;
            int r = max(a, b) + limit;
            int sum = a + b;

            diff[2] += 2;
            diff[l] -= 1;
            diff[sum] -= 1;
            diff[sum + 1] += 1;
            diff[r + 1] += 1;
        }

        int ans = n;
        int current_moves = 0;
        for (int i = 2; i <= 2 * limit; ++i) {
            current_moves += diff[i];
            ans = min(ans, current_moves);
        }

        return ans;
    }
};
