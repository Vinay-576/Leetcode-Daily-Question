class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) {
        sort(tasks.begin(), tasks.end(), [](const vector<int>& a, const vector<int>& b) {
            return (a[1] - a[0]) > (b[1] - b[0]);
        });
        
        int initialEnergy = 0;
        int currentEnergy = 0;
        
        for (const auto& task : tasks) {
            if (currentEnergy < task[1]) {
                initialEnergy += (task[1] - currentEnergy);
                currentEnergy = task[1];
            }
            currentEnergy -= task[0];
        }
        
        return initialEnergy;
    }
};
