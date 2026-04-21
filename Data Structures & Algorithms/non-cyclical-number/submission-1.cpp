class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> sett;

        int t = n;

        while (true) {

            int temp = t;
            int s = 0;

            while (temp > 0) {
                int rem = temp % 10;
                s = s + (rem * rem);
                temp = temp / 10;
            }

            if (s == 1) 
                return true;
            
            if (sett.find(s) != sett.end()) {
                return false;
            }

            sett.insert(s);
            t = s;
        }

        return true;
    }
};
