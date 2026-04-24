class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int longest = 0;
        set<char> sett;

        // p w w k e w
        //     l
        //     r 
        
        int l = 0;
        for (int r = 0; r < s.size(); r++) {
            if (sett.count(s[r])) {
               while (sett.count(s[r])) {
                    sett.erase(s[l]);
                    l++;
                }
            }

            sett.insert(s[r]);
            longest = max(longest, (r-l+1));
        }   

        return longest;
    }
};
