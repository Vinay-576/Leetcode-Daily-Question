class Solution {
public:
    int minElement(vector<int>& nums) {
        int min_sum = 1e9;
        
        for (int x : nums) {
            int current_sum = 0;
            while (x > 0) {
                current_sum += x % 10;
                x /= 10;
            }
            min_sum = min(min_sum, current_sum);
        }
        
        return min_sum;
    }
};
