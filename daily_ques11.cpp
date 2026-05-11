// 2553 separate-the-digits-in-an-array

// Given an array of positive integers nums, return an array answer that consists of the digits of each integer in nums after separating them in the same order they appear in nums.

// To separate the digits of an integer is to get all the digits it has in the same order.

// For example, for the integer 10921, the separation of its digits is [1,0,9,2,1].
 

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> answer;
        for (int val : nums) {
            string s = to_string(val);
            for (char c : s) {
                answer.push_back(c - '0'); 
            }
        }
        return answer;
    }
};

int main() {
    Solution sol;
    
    // Test Case 1
    vector<int> nums1 = {13, 25, 83, 77};
    vector<int> result1 = sol.separateDigits(nums1);
    
    cout << "Result: ";
    for (int n : result1) {
        cout << n << " ";
    }
    cout << endl;

    return 0;
}
