class Solution {
public:
    
    void makeNeighbourOnesToZero(vector<vector<char>>& grid, int i, int j) {
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] == '0') 
            return;
        
        grid[i][j] = '0';

        makeNeighbourOnesToZero(grid, i-1, j);
        makeNeighbourOnesToZero(grid, i, j-1);
        makeNeighbourOnesToZero(grid, i+1, j);
        makeNeighbourOnesToZero(grid, i, j + 1);

        return;
    }

    int numIslands(vector<vector<char>>& grid) {   
        int count = 0;
        int r = grid.size();
        int c = grid[0].size();

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (grid[i][j] == '1') {
                    count++;
                    makeNeighbourOnesToZero(grid,i,j);
                }
            }
        }

        return count;
    }
};
