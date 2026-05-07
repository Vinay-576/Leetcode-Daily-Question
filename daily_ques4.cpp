// 3660 - jump game ix

// You are given an integer array nums.

// From any index i, you can jump to another index j under the following rules:

// Jump to index j where j > i is allowed only if nums[j] < nums[i].
// Jump to index j where j < i is allowed only if nums[j] > nums[i].
// For each index i, find the maximum value in nums that can be reached by following any sequence of valid jumps starting at i.

// Return an array ans where ans[i] is the maximum value reachable starting from index i.

 

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> maxValue(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return {};
        
        vector<int> premax(n), sufmin(n), ans(n);

        premax[0] = nums[0];
        for (int i = 1; i < n; i++) {
            premax[i] = max(premax[i - 1], nums[i]);
        }

        sufmin[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            sufmin[i] = min(sufmin[i + 1], nums[i]);
        }

        int s = 0;
        for (int i = 0; i < n; i++) {
            if (i == n - 1 || premax[i] <= sufmin[i + 1]) {
                int curmax = premax[i];
                for (int j = s; j <= i; j++) {
                    ans[j] = curmax;
                }
                s = i + 1;
            }
        }
        return ans;
    }
};


int main() {
    Solution sol;

    // Test Case 1
    vector<int> nums1 = {2, 1, 3};
    vector<int> result1 = sol.maxValue(nums1);
    
    cout << "Test Case 1: ";
    for (int x : result1) cout << x << " "; 
    cout << endl;

    // Test Case 2
    vector<int> nums2 = {2, 3, 1};
    vector<int> result2 = sol.maxValue(nums2);
    
    cout << "Test Case 2: ";
    for (int x : result2) cout << x << " "; 
    cout << endl;

    return 0;
}