class Solution {
public:
    string convertToTitle(int columnNumber) {
        long long tc = (long long) columnNumber;
        unordered_map<int, char> mapp;

        for (int i = 0; i < 26; i++) 
            mapp[i] = 'A' + i;

        string res = "";

        if (tc < 27){
            string r(1, mapp[tc-1]);
            return r;
        }

        while (tc >= 27) {
            long long mod = (tc - 1) % 26; 
            res.push_back(mapp[mod]);

            tc = (tc - 1) / 26;
        }

        res.push_back(mapp[tc - 1]);

        reverse(res.begin(), res.end());
        return res;
    }
};