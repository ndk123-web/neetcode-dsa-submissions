class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {

        int r = matrix.size();
        int c = matrix[0].size();

        // 1. transpose (so means col become row)
        for (int i = 0; i < r; i++) {

            // only one pair of diagonal swapped
            for (int j = i + 1; j < c; j++) {
                swap(matrix[i][j] , matrix[j][i]);
            }
        }

        // 2. reverse each row so that it will be 90degree shift
        for (int i = 0; i < r; i++)
            reverse(matrix[i].begin(), matrix[i].end());
    }
};
