class Solution {
   public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<pair<int, int>> pairs;
        int r = matrix.size(), c = matrix[0].size();

        // stores {i,j} whose actual element zero
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (matrix[i][j] == 0) pairs.push_back({i, j});
            }
        }

        // at each pair
        for (pair<int, int>& p : pairs) {
            // convert all row and col of that element to zero in place
            int row = p.first;
            int col = p.second;

            // row to 0
            for (int i = 0; i < c; i++) {
                matrix[row][i] = 0;
            }

            // col to 0
            for (int i = 0; i < r; i++) {
                matrix[i][col] = 0;
            }
        }

        return;
    }
};
