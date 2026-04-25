class Solution {
public:
    double myPow(double x, int n) {
        double res = 1;

        bool isNeg = false;
        if (n < 0) 
            isNeg = true;

        for (int i = 0; i < abs(n); i++) {
            res = res * x;
        }

        if (isNeg) 
            return 1 / res;

        return res;
    }
};
