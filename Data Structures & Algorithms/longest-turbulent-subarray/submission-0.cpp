class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int curr_len = 1;
        int max_len = 1;
        int n = arr.size();
        int prev_cmp = 0;

        for (int i = 1; i < n; i++) {
            int cmp = (arr[i] > arr[i-1]) ? 1 : (arr[i] < arr[i-1]) ? -1 : 0;

            // if cmp is 0 then start from 1 as curr_len 
            if (cmp == 0) {
                curr_len = 1;
            }

            // it means both are turbulent
            else if (prev_cmp * cmp == -1) {
                curr_len++;
            }

            // its neighter 0 
            else {
                curr_len = 2;
            }

            prev_cmp = cmp;
            max_len = max(max_len, curr_len);
        }

        return max_len;
    }
};