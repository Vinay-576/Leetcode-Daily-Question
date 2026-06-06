class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n= nums.size();
        vector<int> l(n);
        vector<int> r(n);
        vector<int> ans(n);
        l[0]= 0;
        r[n-1]=0;
        for(int i=1;i<n;i++){
            l[i]=l[i-1]+ nums[i-1];
            r[n-1-i]= r[n-i]+ nums[n-i];
        }
        for(int j=0; j<n; j++){
            ans[j]= abs(l[j]-r[j]);
        }
        return ans;
    }
};
