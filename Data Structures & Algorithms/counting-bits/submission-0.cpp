class Solution {
   public:
    vector<int> countBits(int n) {
        vector<int> result;

        for (int i = 0; i <= n; i++) {
            int count = 0;
            int t = i;
            while (t > 0) {
                if (t & 1) count++;
                t = t >> 1;
            }
            result.push_back(count);
        }

        return result;
    }
};
