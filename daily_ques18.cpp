class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<int> prefixes;
        
        for (int val : arr1) {
            while (val > 0) {
                prefixes.insert(val);
                val /= 10; 
            }
        }
        
        int max_len = 0;
        
        for (int val : arr2) {
            while (val > 0) {
                if (prefixes.count(val)) {
                    int current_len = to_string(val).length();
                    max_len = max(max_len, current_len);
                    break;
                }
                val /= 10;
            }
        }
        
        return max_len;
    }
};
