class Solution {
private:
    vector<int> arr;

    vector<int> mergesort(vector<int>& left, vector<int>& right) {
        vector<int> res;

        int i = 0, j = 0;
        while (i < left.size() && j < right.size()) {
            if (left[i] < right[j]) {
                res.push_back(left[i++]);
            }
            else {
                res.push_back(right[j++]);
            }
        }

        while (i < left.size()) {
            res.push_back(left[i++]);
        }

        while (j < right.size()) {
            res.push_back(right[j++]);
        }

        return res;
    }

    vector<int> merge(int l, int r) {

        if (l == r) {
            return {arr[l]};
        }

        int mid = (l + r) / 2;

        // left one
        vector<int> left = merge(l, mid);

        // right one 
        vector<int> right = merge(mid + 1, r);

        return mergesort(left, right);
    }

public:
    vector<int> sortArray(vector<int>& nums) {
        /*
             5 4 3 2

            (4,5)     (2, 3)

            5  4
        */

        arr = nums;
        return merge(0, nums.size()-1);
    }
};