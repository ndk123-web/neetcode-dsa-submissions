class Solution {
public:
    int reverseBits(int n) {
        int res = 0; // 000000..... (len 32)

        /*
            Logic:
                1. Shift res to left
                2. Update res
                3. Shift n to right
        */

        // because its 32 bit integer (0000..)
        for (int i = 0; i < 32; i++) {
            res = res << 1; // shift res to left by 1 place
            res = res | (n & 1);
            n = n >> 1; // shift n to right by 1 place
        }

        return res;
    }
};