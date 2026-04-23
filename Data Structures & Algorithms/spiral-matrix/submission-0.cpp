class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int r = matrix.size() - 1, c = matrix[0].size() - 1;
        int top = 0, left = 0;
        int bottom = r, right = c;      
        vector<int> res;

        while (left <= right && top <= bottom) {
            
            // Top left to Top right
            for (int i = left; i <= right; i++) {
                res.push_back(matrix[top][i]);
            }

            top++;
            // if (top > bottom)

            if (top > bottom || left > right) break;
            // Top right to bottom left
            for (int i = top; i <= bottom; i++) {
                res.push_back(matrix[i][right]);
            }
            right--;

            if (top > bottom || left > right) break;
            // bottom right to bottom left 
            for (int i = right; i >= left; i--) {
                res.push_back(matrix[bottom][i]);
            }

            bottom--;
            // if (top > bottom) 
            //     break;

            // bottom left to top left
            if (top > bottom || left > right) break;
            for (int i = bottom; i >= top; i--) {
                res.push_back(matrix[i][left]);
            }

            left++;
        }

        return res;
    }
};
