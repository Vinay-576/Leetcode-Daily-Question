class Solution {
public:
    int assignEdgeWeights(vector<vector<int>>& edges) {
        int n = edges.size() + 1;
        vector<vector<int>> adj(n + 1);
        for (const auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        
        int max_depth = 0;
        queue<pair<int, int>> q;
        q.push({1, 0});
        vector<bool> visited(n + 1, false);
        visited[1] = true;
        
        while (!q.empty()) {
            auto [node, depth] = q.front();
            q.pop();
            
            if (depth > max_depth) {
                max_depth = depth;
            }
            
            for (int neighbor : adj[node]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push({neighbor, depth + 1});
                }
            }
        }
        
        if (max_depth == 0) {
            return 0;
        }
        
        long long ans = 1;
        long long base = 2;
        int exp = max_depth - 1;
        int MOD = 1e9 + 7;
        
        while (exp > 0) {
            if (exp % 2 == 1) {
                ans = (ans * base) % MOD;
            }
            base = (base * base) % MOD;
            exp /= 2;
        }
        
        return ans;
    }
};
