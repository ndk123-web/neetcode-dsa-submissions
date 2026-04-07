class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        unordered_map<int,int> mapp;
        int n = hand.size();

        for (int& h : hand) {
            mapp[h]++;
        }      

        sort(hand.begin(), hand.end());

        for (int i = 0; i < n; i++) {

            if (mapp[hand[i]] > 0) {
                mapp[hand[i]]--;

                int sm = hand[i];

                // try to get remaining (n - 1) group
                for (int j = 0; j < groupSize - 1; j++) {
                    if (mapp[sm + 1] > 0) {
                        mapp[sm + 1]--;
                        sm = sm + 1;
                    }
                    else {
                        return false;
                    }
                }
            }
        }

        return true;
    }
};
