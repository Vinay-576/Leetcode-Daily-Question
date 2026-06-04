class Solution {
    int waviness(int n){
        string str = to_string(n);
        int count =0;
        if(str.size()<3) return 0;
        for(int i=1; i<str.size()-1; i++){
            int a= str[i-1];
            int b= str[i];
            int c= str[i+1];
            if(b>a&& b>c) count++;
            if(b<a&& b<c) count++;
        }
        return count;
    };
public:
    int totalWaviness(int num1, int num2) {
        int ans= 0;
        for(int j= num1; j<num2+1; j++){
            ans= ans+ waviness(j);
        }
        return ans;
    }
};
