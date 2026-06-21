class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int sum =0 ;

        for (int cost : costs){
            sum = max(sum, cost);
        }
        vector<int> f(sum+1,0);
        for (int cost : costs){
            f[cost]++;
        }
        int count =0;
        for (int p = 1; p<=sum; p++){
            if (f[p] ==0) continue;

            if (coins < p) break;

            int tobuy = min((long long)f[p], (long long)coins/p);

            count += tobuy;
            coins -= tobuy*p;
        }
        return count;
    }
};
