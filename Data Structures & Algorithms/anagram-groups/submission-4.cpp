class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string, vector<string>> mapp;

        for (string& str : strs) {
            string t = str;
            sort(t.begin(), t.end());
            mapp[t].push_back(str);
        }

        for (auto& p : mapp) {
            res.push_back(p.second);
        }

        return res;
    }
};
