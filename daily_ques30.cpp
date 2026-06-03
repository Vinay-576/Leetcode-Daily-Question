class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int n = landStartTime.size();
        int m = waterStartTime.size();
        
        int minLandFinish = INT_MAX;
        for (int i = 0; i < n; ++i) {
            minLandFinish = min(minLandFinish, landStartTime[i] + landDuration[i]);
        }
        
        int minWaterFinish = INT_MAX;
        for (int i = 0; i < m; ++i) {
            minWaterFinish = min(minWaterFinish, waterStartTime[i] + waterDuration[i]);
        }
        
        int landFirst = INT_MAX;
        for (int i = 0; i < m; ++i) {
            landFirst = min(landFirst, max(waterStartTime[i], minLandFinish) + waterDuration[i]);
        }
        
        int waterFirst = INT_MAX;
        for (int i = 0; i < n; ++i) {
            waterFirst = min(waterFirst, max(landStartTime[i], minWaterFinish) + landDuration[i]);
        }
        
        return min(landFirst, waterFirst);
    }
};
