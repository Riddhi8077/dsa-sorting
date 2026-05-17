class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
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

            int jumpLength = arr[curr];
            
            arr[curr] = -arr[curr];

            int forwardIdx = curr + jumpLength;
            if (forwardIdx < n && arr[forwardIdx] >= 0) {
                q.push(forwardIdx);
            }

            int backwardIdx = curr - jumpLength;
            if (backwardIdx >= 0 && arr[backwardIdx] >= 0) {
                q.push(backwardIdx);
            }
        }

        return false;
    }
};
