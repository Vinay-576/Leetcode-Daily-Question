class Solution {
    struct Node {
        long long cnt;
        long long wav;
    };
    string s;
    Node dp[20][2][11][11][2];
    bool vis[20][2][11][11][2];

    Node dfs(int pos, int tight, int last, int secondLast, int started) {           

        if (pos == s.size()) return {1, 0};
        if (vis[pos][tight][last][secondLast][started]) {
            return dp[pos][tight][last][secondLast][started];
        }
        vis[pos][tight][last][secondLast][started] = true;
        Node res = {0, 0};
        int limit = tight ? s[pos] - '0' : 9;
        for (int d = 0; d <= limit; d++) {
            int ntight = tight && (d == limit);
            if (!started && d == 0) {
                Node nxt = dfs(pos + 1, ntight, 10, 10, 0);
                res.cnt += nxt.cnt;
                res.wav += nxt.wav;
            }
            else {
                if (!started) {
                    Node nxt = dfs(pos + 1, ntight, d, 10, 1);
                    res.cnt += nxt.cnt;
                    res.wav += nxt.wav;
                }
                else if (secondLast == 10) {
                    Node nxt = dfs(pos + 1, ntight, d, last, 1);
                    res.cnt += nxt.cnt;
                    res.wav += nxt.wav;
                }
                else {
                    int add = ((last > secondLast && last > d) || (last < secondLast && last < d));
                    Node nxt = dfs(pos + 1, ntight, d, last, 1);
                    res.cnt += nxt.cnt;
                    res.wav += nxt.wav + add * nxt.cnt;
                }
            }
        }
        return dp[pos][tight][last][secondLast][started] = res;
    }

    long long solve(long long x) {
        if (x < 0) return 0;
        s = to_string(x);
        memset(vis, 0, sizeof(vis));
        return dfs(0, 1, 10, 10, 0).wav;
    }

public:
    long long totalWaviness(long long num1, long long num2) {
        return solve(num2) - solve(num1 - 1);
    }
};
