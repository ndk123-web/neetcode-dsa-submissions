class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        queue<int> q;
        int farthest = 0;
        int n = s.size();

        q.push(0);

        while (!q.empty()) {
            int i = q.front();
            q.pop();

            int st = max(i + minJump, farthest + 1);

            for (int j = st; j < min(i + maxJump + 1, n); j++) {
                if (s[j] == '0') {
                    q.push(j);
                    if (j == n - 1) {
                        return true;
                    }
                }
            }

            farthest = i + maxJump;
        }

        return false;
    }
};