class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<int> component(n, 0);
        int currentComponent = 0;
        
        for (int i = 1; i < n; i++) {
            if (nums[i] - nums[i - 1] > maxDiff) {
                currentComponent++;
            }
            component[i] = currentComponent;
        }
        
        vector<bool> answer(queries.size());
        for (size_t i = 0; i < queries.size(); i++) {
            int u = queries[i][0];
            int v = queries[i][1];
            answer[i] = (component[u] == component[v]);
        }
        
        return answer;
    }
};
