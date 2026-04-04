class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, INT_MAX);

        dp[0] = 0;

        for (int i = 0; i < n - 1; i++) {

            int st = i + 1;
            int end = i + nums[i];

            for (int j = st; j <= end && j < n; j++) {
                dp[j] = min(dp[j], dp[i] + 1);
            }
        }

        return dp[n - 1] == INT_MAX ? 0 : dp[n - 1];
    }
};