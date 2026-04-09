class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.size();
        vector<int> res;
        unordered_map<char,int> mapp;

        // store last index 
        for (int i = 0; i < n; i++) {
            mapp[s[i]] = i; 
        }   

        int st = 0, end = 0;

        for (int i = 0; i < n; i++) {

            end = max(end, mapp[s[i]]);

            if (i == end) {
                res.push_back(end - st + 1);
                st = i + 1;
            }
        }

        return res;
    }
};
