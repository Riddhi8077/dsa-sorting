class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        int numLayers = min(m, n) / 2;

        for (int layer = 0; layer < numLayers; ++layer) {
            vector<int> elements;
            
            for (int j = layer; j < n - layer - 1; ++j) elements.push_back(grid[layer][j]);
            for (int i = layer; i < m - layer - 1; ++i) elements.push_back(grid[i][n - layer - 1]);
            for (int j = n - layer - 1; j > layer; --j) elements.push_back(grid[m - layer - 1][j]);
            for (int i = m - layer - 1; i > layer; --i) elements.push_back(grid[i][layer]);

            int total = elements.size();
            int netK = k % total;
            
            int idx = netK; 
            
            for (int j = layer; j < n - layer - 1; ++j) grid[layer][j] = elements[idx++ % total];
            for (int i = layer; i < m - layer - 1; ++i) grid[i][n - layer - 1] = elements[idx++ % total];
            for (int j = n - layer - 1; j > layer; --j) grid[m - layer - 1][j] = elements[idx++ % total];
            for (int i = m - layer - 1; i > layer; --i) grid[i][layer] = elements[idx++ % total];
        }

        return grid;
    }
};
