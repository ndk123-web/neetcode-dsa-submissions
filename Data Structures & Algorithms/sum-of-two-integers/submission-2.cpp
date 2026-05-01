#include <cmath>

class Solution {
   public:
    int getSum(int a, int b) {

        // means till we get the carry
        while (b != 0) {
            
            // get the carry where 1 and shift that to left side (pass the carry)
            int carry = (a & b) << 1;
            
            // xor of a and b and store in the a 
            a = a ^ b;

            // now change to carry the carry means there are 1 wehere 1 should be there
            b = carry;
        }

        return a;
    }
};
