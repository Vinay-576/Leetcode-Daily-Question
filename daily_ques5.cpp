const int MAX_VAL = 1000005;
int min_prime[MAX_VAL];
bool is_prime[MAX_VAL];

auto init = []() {
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i < MAX_VAL; ++i) {
        is_prime[i] = true;
        min_prime[i] = i;
    }
    for (int i = 2; i * i < MAX_VAL; ++i) {
        if (is_prime[i]) {
            for (int j = i * i; j < MAX_VAL; j += i) {
                is_prime[j] = false;
                if (min_prime[j] == j) min_prime[j] = i;
            }
        }
    }
    return 0;
}();

class Solution {
public:
    int minJumps(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return 0;
        
        int max_val = 0;
        for (int x : nums) {
            if (x > max_val) max_val = x;
        }

        vector<bool> active_primes(max_val + 1, false);
        for (int i = 0; i < n; ++i) {
            if (is_prime[nums[i]]) {
                active_primes[nums[i]] = true;
            }
        }
        
        vector<vector<int>> buckets(max_val + 1);
        for (int i = 0; i < n; ++i) {
            int temp = nums[i];
            while (temp > 1) {
                int p = min_prime[temp];
                if (p <= max_val && active_primes[p]) {
                    buckets[p].push_back(i);
                }
                while (temp % p == 0) temp /= p;
            }
        }

        queue<int> q;
        vector<int> dist(n, -1);
        
        q.push(0);
        dist[0] = 0;
        
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            
            if (u == n - 1) return dist[u];
            
            if (u + 1 < n && dist[u + 1] == -1) {
                dist[u + 1] = dist[u] + 1;
                q.push(u + 1);
            }
            if (u - 1 >= 0 && dist[u - 1] == -1) {
                dist[u - 1] = dist[u] + 1;
                q.push(u - 1);
            }
            
            if (is_prime[nums[u]]) {
                int p = nums[u];
                if (active_primes[p]) {
                    for (int v : buckets[p]) {
                        if (dist[v] == -1) {
                            dist[v] = dist[u] + 1;
                            q.push(v);
                        }
                    }
                    active_primes[p] = false; 
                }
            }
        }
        
        return -1;
    }
};
