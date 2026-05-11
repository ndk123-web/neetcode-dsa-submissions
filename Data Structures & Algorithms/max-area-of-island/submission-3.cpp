class Solution {
   public:
    int greaterOnes(vector<vector<int>>& grid, int i, int j) {
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] == 0) return 0;

        grid[i][j] = 0;

        return 1 + greaterOnes(grid, i -1, j) + greaterOnes(grid, i +1, j) + greaterOnes(grid, i, j - 1) + greaterOnes(grid, i, j + 1);
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        int maxOne = 0;

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (grid[i][j] == 1) {
                    maxOne = max(maxOne, greaterOnes(grid, i, j));
                }
            }
        }

        return maxOne;
    }
};
