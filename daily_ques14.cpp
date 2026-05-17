class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        queue<int> q;
        q.push(start);
        
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            
            if (arr[curr] == 0) {
                return true;
            }
            
            if (arr[curr] < 0) {
                continue;
            }
            
            int forward = curr + arr[curr];
            int backward = curr - arr[curr];
            
            arr[curr] = -arr[curr];
            
            if (forward < arr.size() && arr[forward] >= 0) {
                q.push(forward);
            }
            if (backward >= 0 && arr[backward] >= 0) {
                q.push(backward);
            }
        }
        
        return false;
    }
};
