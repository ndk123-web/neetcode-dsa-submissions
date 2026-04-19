class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int r = matrix.size();
        int c = matrix[0].size();

        vector<vector<int>> mat(c, vector<int>(r, INT_MAX));

        // c = 3, r = 2
        for (int i = 0; i < c; i++) {
            for (int j = 0; j < r; j++) {
                mat[i][j] = matrix[j][i];
            }
        }

        return mat;
    }
};