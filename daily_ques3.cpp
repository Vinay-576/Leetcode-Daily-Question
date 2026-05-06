// 1861 - rotating the box

// You are given an m x n matrix of characters boxGrid representing a side-view of a box. Each cell of the box is one of the following:

// A stone '#'
// A stationary obstacle '*'
// Empty '.'
// The box is rotated 90 degrees clockwise, causing some of the stones to fall due to gravity. Each stone falls down until it lands on an obstacle, another stone, or the bottom of the box. Gravity does not affect the obstacles' positions, and the inertia from the box's rotation does not affect the stones' horizontal positions.

// It is guaranteed that each stone in boxGrid rests on an obstacle, another stone, or the bottom of the box.

// Return an n x m matrix representing the box after the rotation described above.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        int n = boxGrid.size();
        int m = boxGrid[0].size();

        // Apply gravity
        for (int i = 0; i < n; i++) {
            int emp = m - 1;
            for (int j = m - 1; j >= 0; j--) {
                if (boxGrid[i][j] == '*') {
                    emp = j - 1;
                } 
                else if (boxGrid[i][j] == '#') {
                    swap(boxGrid[i][j], boxGrid[i][emp]);
                    emp--;
                }
            }
        }

        // Rotate 90deg clockwise
        vector<vector<char>> rot(m, vector<char>(n));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                rot[j][n - 1 - i] = boxGrid[i][j];
            }
        }

        return rot;
    }
};


void printBox(const vector<vector<char>>& box) {
    for (const auto& row : box) {
        for (char c : row) cout << c << " ";
        cout << endl;
    }
}

int main() {
    Solution sol;
    vector<vector<char>> box = {
        {'#', '.', '*', '.'},
        {'#', '#', '*', '.'}
    };

    cout << "Original Box:" << endl;
    printBox(box);

    vector<vector<char>> result = sol.rotateTheBox(box);

    cout << "\nAfter Gravity and Rotation:" << endl;
    printBox(result);

    return 0;
}