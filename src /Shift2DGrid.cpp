class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        int totalElements = m * n;
        
        k = k % totalElements;
        
        vector<vector<int>> result(m, vector<int>(n));
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int flatIndex = i * n + j;
                
                int newFlatIndex = (flatIndex + k) % totalElements;
                
                int newRow = newFlatIndex / n;
                int newCol = newFlatIndex % n;
                
                result[newRow][newCol] = grid[i][j];
            }
        }
        
        return result;
    }
};
