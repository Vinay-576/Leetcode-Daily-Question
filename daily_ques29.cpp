class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int n = landStartTime.size();
        int m = waterStartTime.size();
        long long ans = LLONG_MAX;

        for (int i = 0; i < n; i++) {
            long long l = (long long)landStartTime[i] + landDuration[i];
            for (int j = 0; j < m; j++) {
                long long w = (long long)waterStartTime[j] + waterDuration[j];
                long long f1 = max(l, (long long)waterStartTime[j]) + waterDuration[j];
                long long f2 = max(w, (long long)landStartTime[i]) + landDuration[i];
                ans = min(ans, min(f1, f2));
            }
        }
        return (int)ans;
    }
};
