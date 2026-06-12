class Solution {
private:
    int maxLog;
    vector<int> depth;
    vector<vector<int>> parent;
    long long MOD = 1e9 + 7;

    void dfs(int node, int p, int d, const vector<vector<int>>& adj) {
        depth[node] = d;
        parent[node][0] = p;
        for (int neighbor : adj[node]) {
            if (neighbor != p) {
                dfs(neighbor, node, d + 1, adj);
            }
        }
    }
    void precomputeLCA(int n) {
        for (int i = 1; i < maxLog; ++i) {
            for (int node = 1; node <= n; ++node) {
                if (parent[node][i - 1] != -1) {
                    parent[node][i] = parent[parent[node][i - 1]][i - 1];
                }
            }
        }
    }

    int getLCA(int u, int v) {
        if (depth[u] < depth[v]) swap(u, v);

        for (int i = maxLog - 1; i >= 0; --i) {
            if (depth[u] - (1 << i) >= depth[v]) {
                u = parent[u][i];
            }
        }

        if (u == v) return u;

        for (int i = maxLog - 1; i >= 0; --i) {
            if (parent[u][i] != parent[v][i]) {
                u = parent[u][i];
                v = parent[v][i];
            }
        }

        return parent[u][0];
    }

    long long power(long long base, long long exp) {
        long long res = 1;
        base %= MOD;
        while (exp > 0) {
            if (exp % 2 == 1) res = (res * base) % MOD;
            base = (base * base) % MOD;
            exp /= 2;
        }
        return res;
    }

public:
    vector<int> assignEdgeWeights(vector<vector<int>>& edges, vector<vector<int>>& queries) {
        int n = edges.size() + 1;
        maxLog = log2(n) + 2;

        vector<vector<int>> adj(n + 1);
        for (const auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        depth.assign(n + 1, 0);
        parent.assign(n + 1, vector<int>(maxLog, -1));

        dfs(1, -1, 0, adj);
        precomputeLCA(n);

        vector<int> answer;
        answer.reserve(queries.size());

        for (const auto& query : queries) {
            int u = query[0];
            int v = query[1];

            if (u == v) {
                answer.push_back(0);
                continue;
            }

            int lca = getLCA(u, v);
            int pathLength = depth[u] + depth[v] - 2 * depth[lca];

            answer.push_back(power(2, pathLength - 1));
        }

        return answer;
    }
};
