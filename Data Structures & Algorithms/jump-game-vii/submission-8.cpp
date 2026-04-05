class Solution {
public:
    vector<int> dp;
    int n;

    bool dfs(int i, string& s, int minJump, int maxJump) {
        if (dp[i] != -1) {
            return dp[i];
        }

        dp[i] = 0;
        for (int j = i + minJump; j <= min(i + maxJump, n-1) ; j++) {
           if (s[j] == '0' && dfs(j, s, minJump, maxJump)) {
                
                // if true then break from the loop
                dp[i] = 1;
                break;
           }
        }

        return dp[i];
    }

    bool canReach(string s, int minJump, int maxJump) {
        n = s.size();
        dp.assign(n, -1);
        dp[n-1] = 1;

        return dfs(0,s,minJump,maxJump);      
    }
};