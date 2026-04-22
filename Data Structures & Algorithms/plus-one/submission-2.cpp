class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 1;
        int n = digits.size();
        vector<int> res;

        for (int i = n - 1; i >= 0; i--) {
            int sum = digits[i] + carry;
            res.push_back(sum % 10);
            carry = sum / 10;
        }

        if (carry) {
            res.push_back(1);
        }

        reverse(res.begin(), res.end());

        return res;
    }
};