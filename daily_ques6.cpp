// 1914 - cyclically rotating a grid

// You are given an m x n integer matrix grid​​​, where m and n are both even integers, and an integer k.

// The matrix is composed of several layers, which is shown in the below image, where each color is its own layer:

 

class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        int numLayers = min(m, n) / 2;

        for (int layer = 0; layer < numLayers; ++layer) {
            vector<int> elements;
            
            // 1. Extract elements in counter-clockwise order
            // Top row
            for (int j = layer; j < n - layer - 1; ++j) elements.push_back(grid[layer][j]);
            // Right col
            for (int i = layer; i < m - layer - 1; ++i) elements.push_back(grid[i][n - layer - 1]);
            // Bottom row
            for (int j = n - layer - 1; j > layer; --j) elements.push_back(grid[m - layer - 1][j]);
            // Left col
            for (int i = m - layer - 1; i > layer; --i) elements.push_back(grid[i][layer]);

            // 2. Calculate effective rotation
            int len = elements.size();
            int netRotation = k % len;
            
            // 3. Re-insert elements starting from index 'netRotation'
            int idx = netRotation;
            auto getNext = [&]() { 
                int val = elements[idx];
                idx = (idx + 1) % len;
                return val;
            };

            for (int j = layer; j < n - layer - 1; ++j) grid[layer][j] = getNext();
            for (int i = layer; i < m - layer - 1; ++i) grid[i][n - layer - 1] = getNext();
            for (int j = n - layer - 1; j > layer; --j) grid[m - layer - 1][j] = getNext();
            for (int i = m - layer - 1; i > layer; --i) grid[i][layer] = getNext();
        }
        
        return grid;
    }
};


int main() {
    Solution sol;
    vector<vector<int>> grid = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
    int k = 2;
    
    auto result = sol.rotateGrid(grid, k);
    
    for (const auto& row : result) {
        for (int val : row) cout << val << " ";
        cout << endl;
    }
    return 0;
}