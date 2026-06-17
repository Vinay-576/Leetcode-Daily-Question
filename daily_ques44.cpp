class Solution {
public:
    char processStr(string s, long long k) {
        int n = s.size();
        vector<long long> len(n);
        long long cur = 0;
        const long long LIM = 4e18;
        for (int i = 0; i < n; i++) {
            char c = s[i];
            if (c == '*') {
                if (cur > 0) cur--;
            }
            else if (c == '#') {
                cur = min(LIM, cur * 2);
            }
            else if (c == '%') {
            }
            else {
                cur++;
            }
            len[i] = cur;
        }

        if (k >= cur) return '.';
        for (int i = n - 1; i >= 0; i--) {
            char c = s[i];
            long long prev = (i == 0 ? 0 : len[i - 1]);
            if ('a' <= c && c <= 'z') {
                if (k == prev) return c;
            }
            else if (c == '#') {
                if (prev > 0) {
                    k %= prev;
                }
            }
            else if (c == '%') {
                k = len[i] - 1 - k;
            }
            else if (c == '*') {
            }
        }
        return '.';
    }
};
